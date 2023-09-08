import tkinter as tk

class TableauValeur:

    def __init__(self, x, y, temps):
        self.x = x
        self.y = y
        self.temps = temps
        self.dessiner_tableau()
        self.window.mainloop()


    def dessiner_tableau(self):
        self.window = tk.Tk()
        self.window.geometry("600x600")
        self.window.title("tableau de valeurs")

        self.frame = tk.Frame(self.window)
        self.frame.pack(fill="both", expand=True)
        
        self.canvas = tk.Canvas(self.frame) 
        self.canvas.pack(side="left", fill="both", expand=True)     

        self.scrollbar = tk.Scrollbar(self.frame, orient="vertical", command=self.canvas.yview)
        self.scrollbar.pack(side="right", fill="y")  

        self.canvas.config(yscrollcommand=self.scrollbar)
        self.canvas.bind("<Configure>", lambda event: self.canvas.config(scrollregion=self.canvas.bbox('all')))

    
        self.canvas.create_rectangle(150, 20, 450, 60*(len(self.x)+1))
        for i in range(1, len(self.x)+1):
            self.canvas.create_line(150, 60*i, 450, 60*i)
        for i in range(1, 3):
            self.canvas.create_line(150+100*i, 20, 150+100*i, 60*(len(self.x)+1))
        self.canvas.create_text(200, 30, text="x")
        self.canvas.create_text(300, 30, text="y")
        self.canvas.create_text(400, 30, text="temps")
        for i in range(len(self.x)):
            self.canvas.create_text(200, 30+(i+1)*60, text=self.x[i])
            self.canvas.create_text(300, 30+(i+1)*60, text=self.y[i])
            self.canvas.create_text(400, 30+(i+1)*60, text=self.temps[i])


