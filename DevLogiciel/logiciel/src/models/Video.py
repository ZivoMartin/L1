import tkinter as tk
from tkinter import messagebox
import PIL.Image, PIL.ImageTk
import cv2
from tkinter import filedialog
import os

class Video:

    def __init__(self, window, view):
        self.window = window
        self.view = view
        self.canvas = tk.Canvas(self.window)
        self.color1 = "white"
        self.color2 = "red"
        self.delay = 15   # ms
        self.liste_x = []        
        self.liste_y = []
        self.liste_temps = []
        self.pause = True
        self.en_place=False
        self.extentions_accepted = ['.mp4', '.mov', '.avi', '.wmv', '.mkv', '.flv', '.mpg', '.mpeg', '.m4v', '.webm']
        self.video_fini = False

    def open_file(self):
        file_path = filedialog.askopenfilename()
        if file_path != "" and os.path.splitext(file_path)[1] in self.extentions_accepted:
            self.delete_video
            self.canvas.pack(side='top')
            self.width = 800
            self.height = 600
            self.canvas_barre = tk.Canvas(self.canvas, height=10, width=800)
            self.canvas.create_window((0, self.height), window=self.canvas_barre, anchor="sw")
            self.canvas.config(width = self.width, height = self.height)
            self.cap = cv2.VideoCapture(file_path)
            
            self.nb_frame = int(self.cap.get(cv2.CAP_PROP_FRAME_COUNT))
            self.avancement_barre = int(self.width/int(self.nb_frame-1))
            self.buttons = [None]*(self.nb_frame-1)
            self.en_place = True
            self.numero_frame = 0
            for i in range(self.nb_frame-1):
                self.buttons[i] = tk.Button(self.canvas_barre, bg=self.color1, command=lambda i=i: self.that_frame(i))
                self.canvas_barre.create_window((self.avancement_barre*i, 0), window=self.buttons[i], anchor="nw")
            self.next_frame()
    
    def open_fileE(self, event):
        self.open_file()
    

    def delete_video(self):
        if self.en_place:
            self.canvas.delete("all")
            self.en_place = False
     
        
    def deplacement_barre(self, i, j):
        if(i<j):
            while(i <= j):
                self.buttons[i].config(bg=self.color2)
                i+=1
        else:    
            if(i>=self.nb_frame):
                i = self.nb_frame-2    
            while(i != j):
                self.buttons[i].config(bg=self.color1)
                i-=1
        

    def get_frame(self):  
        if self.en_place: 
            try:
                if self.cap.isOpened():
                    ret, frame = self.cap.read()
                    self.buttons[self.numero_frame].config(bg=self.color2)
                    return (ret, cv2.cvtColor(frame, cv2.COLOR_BGR2RGB))
            except:
                self.buttons[189].config(bg=self.color2)
                if(not self.pause):
                    self.pause_video()
                self.video_fini = True
                messagebox.showerror(title='Alert', message="La video est fini et si un pointage etait en cours, il s'est arrêté")
                return(False, False)



    def play_video(self):
        if self.en_place: 
            ret, frame = self.get_frame()
            if ret:
                frame = cv2.resize(frame, (self.width, self.height))
                self.photo = PIL.ImageTk.PhotoImage(image = PIL.Image.fromarray(frame))
                self.canvas.create_image(0, 0, image = self.photo, anchor = "nw")
                self.numero_frame += 1
            if not self.pause:
                self.window.after(self.delay, self.play_video)
    
    def lire_video(self):
        if self.pause and self.en_place:
            self.pause_video()
            self.play_video()
        elif not self.en_place:
            messagebox.showerror(title='Alert', message='veuillez charger une video.')


    def get_previous_frame(self):
        if self.en_place:
            current_frame = int(self.cap.get(cv2.CAP_PROP_POS_FRAMES))
            if current_frame > 1:  
                self.cap.set(cv2.CAP_PROP_POS_FRAMES, current_frame-2) 
                ret, frame = self.cap.read()  
                if ret:
                    return (ret, cv2.cvtColor(frame, cv2.COLOR_BGR2RGB))
            else:  
                messagebox.showerror(title='Alert', message='You are at the beginning of the video.')
                return(False, False)
    
    def get_last_frame(self):
        if self.en_place:
            success = False
            i = 0
            while not success:
                i+=1
                last_frame_index = int(self.cap.get(cv2.CAP_PROP_FRAME_COUNT)) - i
                self.cap.set(cv2.CAP_PROP_POS_FRAMES, last_frame_index)
                success, frame = self.cap.read()
            self.deplacement_barre(self.numero_frame, last_frame_index)
            self.numero_frame = last_frame_index
            return (success, cv2.cvtColor(frame, cv2.COLOR_BGR2RGB))
           
    def afficher_frame(self, ret, frame):
        if ret:
            frame = cv2.resize(frame, (self.width, self.height))
            self.photo = PIL.ImageTk.PhotoImage(image = PIL.Image.fromarray(frame))
            self.canvas.create_image(0, 0, image = self.photo, anchor = tk.NW)

    def last_frame(self):
        if self.pause and self.en_place:
            ret, frame = self.get_last_frame()
            self.afficher_frame(ret, frame)
            
    def get_first_frame(self):
        if self.en_place:
            self.cap.set(cv2.CAP_PROP_POS_FRAMES, 0) 
            ret, frame = self.cap.read()  
            if ret:
                return (ret, cv2.cvtColor(frame, cv2.COLOR_BGR2RGB))


    def first_frame(self):
        if self.pause and self.en_place:
            self.deplacement_barre(self.numero_frame, 0)
            self.numero_frame = 1
            ret, frame = self.get_first_frame()
            self.afficher_frame(ret, frame)


    def previous_frame(self):
        if self.pause and self.en_place:
            ret, frame = self.get_previous_frame()
            if(self.numero_frame>=190):
                self.buttons[189].config(bg=self.color1)
            else:
                self.buttons[self.numero_frame].config(bg=self.color1)
            self.numero_frame -= 1
            self.afficher_frame(ret, frame)

    
    def next_frame(self):
        if self.pause and self.en_place:
            ret, frame = self.get_frame()
            self.numero_frame += 1
            self.afficher_frame(ret, frame)


    def get_that_frame(self, i):
        if self.en_place:
            self.cap.set(cv2.CAP_PROP_POS_FRAMES, i) 
            ret, frame = self.cap.read()  
            if ret:
                return (ret, cv2.cvtColor(frame, cv2.COLOR_BGR2RGB))


    def that_frame(self, i):
        a = 1
        if(not self.pause):
            self.pause_video
            a = 0
        ret, frame = self.get_that_frame(i)
        self.deplacement_barre(self.numero_frame, i)
        self.numero_frame = i
        self.afficher_frame(ret, frame)
        if(a == 0):
            self.pause_video


    def pause_video(self):
        if self.en_place:
            if self.pause:
                self.view.pause.config(text="⏸")
                self.pause = False
                self.play_video()
            else:
                self.view.pause.config(text="▶")
                self.pause = True
        
    def __del__(self):

        if (self.en_place and self.cap.isOpened()):
            self.cap.release()





