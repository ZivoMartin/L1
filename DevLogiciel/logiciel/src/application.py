from Controllers.Controller import Controller
from models.Video import Video
from models.graphe import Graphe
from PIL import *
from views.View import View
import tkinter as tk


class Application(tk.Tk):

    def __init__(self):

        super().__init__()
        view = View(self)
        video = Video(self, view)
        graphe = Graphe(video, view)
        controller = Controller(video, view, graphe)
        view.setController(controller)
        
        

if __name__ == '__main__':
    app = Application()
    app.mainloop()  
