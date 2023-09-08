from tkinter import filedialog
from models.FileRepo import FileRepo

class Controller:
    
    def __init__(self, video, view, graphe):
        self.video = video
        self.view = view
        self.graphe = graphe
        self.view.file_menu.add_command(label="charger un fichier video", command= video.open_file)
        self.view.file_menu.add_command(label="lire la video", command=video.lire_video)
        self.view.file_menu.add_command(label="retirer le fichier video", command=video.delete_video)
        self.view.file_menu.add_command(label="import to csv", command= self.export_csv)
        self.view.file_menu.add_command(label="quitter", command=view.parent.destroy)
        self.view.edit_menu.add_command(label="Origine du repère", command= self.graphe.activer_origin)
        self.view.edit_menu.add_command(label="Echelle", command= self.graphe.activer_echelle)
        self.view.edit_menu.add_command(label="Placer des points", command= self.graphe.activer_points)

        self.graphe.valid_entry.config(command=self.graphe.create_echelle)
        self.view.pause.config(command=self.video.pause_video)
        self.view.img_suivante.config(command=video.next_frame)
        self.view.img_precedente.config(command=video.previous_frame)
        self.view.debut.config(command=video.first_frame)
        self.view.fin.config(command=video.last_frame)
        self.video.canvas.bind("<Button-1>", self.graphe.clic_video)
        self.video.canvas.bind("<Control-z>", self.graphe.delete_last_point)
        self.video.window.bind("<Control-o>", self.video.open_fileE)
        self.video.window.bind("<Control-q>", self.graphe.activer_pointsE)


    

    def PauseSpace(self, event):
        self.video.Pause
    
    def export_csv(self):
        file_path = filedialog.askdirectory()
        fichier = FileRepo(self.video.liste_x, self.video.liste_y, self.video.liste_temps)
        fichier.transform2csv("points.csv", file_path)

    
        
        
        

    
   

   
    
            
