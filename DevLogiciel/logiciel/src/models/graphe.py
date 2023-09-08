from tkinter import messagebox
import tkinter as tk
from models.tableauValeur import TableauValeur
from models.TracerGraphe import TracerGraphe

class Graphe:

    def __init__(self, video, view):
        self.video = video
        self.view = view

        self.point_actived = False

        self.echelle_active = False
        self.echelle_placed = 0
        self.pointEchelle1X = None
        self.pointEchelle1Y = None
        self.nb_pixel = None
        self.point_echelle1 = None
        self.point_echelle2 = None
        self.entry_en_place = False
        self.echelle = None


        self.origin_placed = False
        self.origin = False
        self.originX = 0
        self.originY = 0

        self.frame_entry = tk.Frame(self.view.parent)
        self.frame_entry.pack(side="left")
        self.entry_label = tk.Label(self.frame_entry, text="Combien est-que cela represente ?")
        self.echelle_entry = tk.Entry(self.frame_entry)
        self.valid_entry = tk.Button(self.frame_entry, text="Valider")
        
        self.previous_point = -1   
        self.i = 0     



    def clic_video(self, event):
        if(self.point_actived):
            if(self.video.pause and self.video.en_place):
                self.video.canvas.focus_set()
                x = event.x - self.originX 
                y = abs(event.y-self.video.width) - self.originY
                if(self.video.numero_frame not in self.video.liste_temps):
                    self.video.liste_x.append(x)
                    self.video.liste_y.append(y)
                    self.video.liste_temps.append((self.video.numero_frame))
                    self.previous_point = len(self.video.liste_x)-1
                    self.i = 0
                else:
                    i = 0
                    while(self.video.liste_temps[i] != self.video.numero_frame):
                        i+=1
                    self.video.liste_x[i] = x
                    self.video.liste_y[i] = y
                    self.video.liste_temps[i] = self.video.numero_frameF
                    self.previous_point = i
                    self.i = 0
                self.video.next_frame()
                if(self.video.video_fini):
                    self.reset_pointageEnd()

        elif(self.echelle_active and self.echelle_placed != -1):
            self.echelle_placed += 1
            if(self.echelle_placed == 1):
                self.point_echelle1 = self.video.canvas.create_rectangle(event.x-2, event.y-2, event.x+2, event.y+2, fill="red")
                self.pointEchelle1X = event.x
                self.pointEchelle1Y = event.y
            else:
                if(event.y <= self.pointEchelle1Y + 15 and event.y >= self.pointEchelle1Y - 15):
                    self.point_echelle2 = self.video.canvas.create_rectangle(event.x-2, event.y-2, event.x+2, event.y+2, fill="red")
                    self.echelle_active = False
                    self.nb_pixel = max(event.x, self.pointEchelle1X) - min(event.x, self.pointEchelle1X)
                    self.entry_en_place = True
                    self.frame_entry.after(1, self.pack_entry)
                else:
                    messagebox.showerror(title='error', message= "Vous devez placer vos points à l'horizontal")

        elif(self.origin and not self.origin_placed):
            self.originY = abs(event.y - self.video.width)
            self.originX = event.x
            self.origin_placed = True
            self.origin = False
            messagebox.showinfo(title='origine', message= "Vous avez bien placé le point d'origine !")

        
    def activer_points(self):
        if(self.echelle_placed == -1 and self.origin_placed and self.video.en_place):
            self.point_actived = True
            self.view.parent.bind("<Escape>", self.reset_pointage)
            self.actualiser_menu("video_placed", "point_actived")
            messagebox.showinfo(title='Echelle', message= "Vous pouvez maintenant placer des points !")
        elif(not self.echelle_placed == -1 and not self.origin_placed and self.video.en_place):
            messagebox.showerror(title='Alert', message= "Vous devez indiquer le point d'origine ainsi que l'echelle")
        elif(not self.echelle_placed == -1 and self.video.en_place):
            messagebox.showerror(title='Alert', message= "Vous devez indiquer l'echelle")
        elif(not self.origin_placed and self.video.en_place):
            messagebox.showerror(title='Alert', message= "Vous devez indiquer le point d'origine")

    def activer_pointsE(self, event):
        self.activer_points()

    def activer_echelle(self):
        if(self.video.en_place):
            self.view.edit_menu.delete("Echelle")
            if(self.echelle_placed == 0):
                messagebox.showinfo(title='Echelle', message= "Vous devez placer deux points à l'horizontal")
            self.echelle_active = True
            self.origin = False
    

    def activer_origin(self):
        if(self.video.en_place):
            if(self.entry_en_place):
                messagebox.showerror("finissez de placer l'echelle !")
                return
            self.origin = True
            self.echelle_active = False

    def afficher_donnees(self):
        TableauValeur(self.video.liste_x, self.video.liste_y, self.video.liste_temps)


    def create_echelle(self):
        result = self.echelle_entry.get()

        chiffres = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10']
        if(result == ""):
                messagebox.showerror(title='Alert', message= "Il semble que vous n'ayez pas inscris de données")
                return        
        for i in range(len(result)):
            if result[i] not in chiffres:
                messagebox.showerror(title='Alert', message= "Il semble que vous n'ayez pas inscris les bonnes données, n'ecrivez rien d'autre que des nombres.")
                return
        self.echelle_placed = -1
        self.video.canvas.delete(self.point_echelle1)
        self.video.canvas.delete(self.point_echelle2)
        

        self.echelle = int(result)/self.nb_pixel
        self.frame_entry.destroy()
        self.entry_en_place = False
        messagebox.showinfo(title='Echelle', message= "Vous avez bien placé votre echelle !")


    def pack_entry(self):
        self.entry_label.pack()
        self.echelle_entry.pack()
        self.valid_entry.pack()

    def reset_pointage(self, event):
        messagebox.showinfo(title='fin', message="Vous avez arrêté le pointage, vous pouvez relancer le pointage dans le menu edit")
        self.point_actived = False
        self.actualiser_menu("point_actived", "point_pause")
    
    def reset_pointageEnd(self):
        self.point_actived = False
        self.actualiser_menu("point_actived", "point_pause")
    

    def stop_pointage(self, moment):
        self.point_actived = False
        self.origin_placed = False
        self.origin = False
        self.originX = 0
        self.originY = 0
        self.video.video_fini = False
        self.video.liste_x = []
        self.video.liste_y = []
        self.video.liste_temps
        self.actualiser_menu(moment, "video_placed")
        


    def reprendre_pointage(self):
        self.point_actived = True
        self.actualiser_menu("point_pause", "point_actived")
        

        
    def actualiser_menu(self, previous, moment):
        if(moment == "point_actived" and previous == "video_placed"):
            self.view.edit_menu.delete("Origine du repère")
            self.view.edit_menu.delete("Placer des points")

        elif(moment == "point_actived" and previous == "point_pause"):
            self.view.edit_menu.delete("Reprendre le pointage")
            self.view.edit_menu.delete("Recommencer le pointage")
            self.view.edit_menu.delete("Afficher les données")
            self.view.view_menu.delete("afficher y(x)")
            self.view.view_menu.delete("afficher x(t)")
            self.view.view_menu.delete("afficher y(t)")
        elif(moment == "point_pause" and previous == "point_actived"):
            self.view.view_menu.add_command(label="afficher y(x)", command= lambda: self.dessiner_graphe(self.video.liste_x, self.video.liste_y, "x", "y"))
            self.view.view_menu.add_command(label="afficher x(t)", command= lambda: self.dessiner_graphe(self.video.liste_temps, self.video.liste_x, "temps", "x"))
            self.view.view_menu.add_command(label="afficher y(t)", command= lambda: self.dessiner_graphe(self.video.liste_temps, self.video.liste_y, "temps", "y"))
            self.view.edit_menu.add_command(label="Reprendre le pointage", command= self.reprendre_pointage)
            self.view.edit_menu.add_command(label="Afficher les données", command= self.afficher_donnees)
            self.view.edit_menu.add_command(label="Recommencer le pointage", command= lambda: self.stop_pointage("point_pause"))
        elif(moment == "video_placed" and previous == "point_pause"):
            self.view.view_menu.delete("afficher y(x)")
            self.view.view_menu.delete("afficher x(t)")
            self.view.view_menu.delete("afficher y(t)")
            self.view.edit_menu.delete("Reprendre le pointage")
            self.view.edit_menu.delete("Afficher les données")
            self.view.edit_menu.delete("Recommencer le pointage")
            self.view.edit_menu.add_command(label="Origine du repère", command= self.activer_origin)
            self.view.edit_menu.add_command(label="Placer des points", command= self.activer_points)
        elif(moment == "video_placed" and previous == "point_actived"):
            self.view.edit_menu.add_command(label="Origine du repère", command= self.activer_origin)
            self.view.edit_menu.add_command(label="Placer des points", command= self.activer_points)

    
    def dessiner_graphe(self, x, y, nom_x, nom_y):
        graphe = TracerGraphe(x, y, nom_x, nom_y)


    def delete_last_point(self, event):
        if(len(self.video.liste_x) != 0):
            del self.video.liste_x[self.previous_point - self.i]
            del self.video.liste_y[self.previous_point - self.i]
            del self.video.liste_temps[self.previous_point - self.i]
            self.video.previous_frame()
            self.i+=1




