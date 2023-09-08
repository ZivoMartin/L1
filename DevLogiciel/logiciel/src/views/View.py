import tkinter as tk
from PIL import *


 
class View(tk.Frame):
    

    def __init__(self, parent):
        super().__init__(parent)
        self.parent = parent
        self.parent.title('Video Tracker')
        self.parent.geometry("500x500")
        self.parent.config(bg='black')
        my_menu = tk.Menu(self)
        self.parent.config(menu=my_menu)
        self.file_menu = tk.Menu(my_menu)
        self.view_menu = tk.Menu(my_menu)
        self.edit_menu = tk.Menu(my_menu)
        my_menu.add_cascade(label="File", menu=self.file_menu)
        my_menu.add_cascade(label="view", menu=self.view_menu)
        my_menu.add_cascade(label="edit", menu=self.edit_menu)

        
        self.button_frame = tk.Frame(self.parent)
        self.centered_frame = tk.Frame(self.button_frame, background="#FFFFFF")
        self.button_frameDroite = tk.Frame(self.centered_frame)
        self.button_frameGauche = tk.Frame(self.centered_frame)
        
        self.button_frame.pack(side="bottom", fill="x")
        self.centered_frame.pack(side = "bottom")
        self.button_frameDroite.pack(side="right", fill="x")
        self.button_frameGauche.pack(side="left", fill="x")


        # création des boutons
        self.iconedebut = tk.PhotoImage(file = r"C:\Users\zivom\OneDrive\Bureau\DevLogiciel\logiciel\ressources\first_frame.png")
        self.iconefin = tk.PhotoImage(file = r"C:\Users\zivom\OneDrive\Bureau\DevLogiciel\logiciel\ressources\last_frame.png")

        self.iconedebut = self.iconedebut.subsample(20, 20)
        self.iconefin = self.iconefin.subsample(20, 20)
        
        self.pause = tk.Button(self.centered_frame, text="▶")
        self.img_suivante = tk.Button(self.button_frameDroite, text="⏭")
        self.img_precedente = tk.Button(self.button_frameGauche, text="⏮")
        self.debut = tk.Button(self.button_frameGauche, image=self.iconedebut)
        self.fin = tk.Button(self.button_frameDroite, image=self.iconefin)

        self.debut.pack(side="left", in_=self.button_frameGauche)
        self.img_precedente.pack(side="left", in_=self.button_frameGauche)
        self.pause.pack()
        self.fin.pack( side="right", in_=self.button_frameDroite)
        self.img_suivante.pack(side="right", in_=self.button_frameDroite)


        
        
    def setController(self, controller):
        self.controller = controller

        

    

