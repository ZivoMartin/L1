import tkinter as tk

class TracerGraphe:

    def __init__(self, x, y, nom_x, nom_y):
        self.x = x
        self.y = y
        self.nom_x = nom_x
        self.nom_y = nom_y
        self.maxY = max(self.y)
        self.maxX = max(self.x)
        self.minX = min(self.x)
        self.minY = min(self.y)
        self.dessiner_graphe()
        self.graphique.mainloop()

        


    def dessiner_graphe(self):
        self.graphique = tk.Tk()
        if(self.nom_x == "temps"):
            self.graphique.title(self.nom_y+"en fonction du temps")
        else:
            self.graphique.title("y en fonction de x")
        self.graphique.geometry("1000x600")
        self.canvas = tk.Canvas(self.graphique, width=1000, height=600)
        self.canvas.place(x=0, y=0)
        if(self.maxX<0 or self.minX<0):
            distance_intervalleX = self.maxX - self.minX
        else:
            distance_intervalleX = self.maxX + abs(self.minX)
        
        if(self.maxY<0 or self.minY<0):
            distance_intervalleY = self.maxY - self.minY
        else:
            distance_intervalleY = self.maxY + abs(self.minY)

        if(distance_intervalleX >= 700):
            nx=30
        elif(abs(self.maxX) + abs(self.minX) >= 300):
            nx=20
        elif(abs(self.maxX) + abs(self.minX) >= 30):           
            nx=10
        else:
            nx=1
        startX = self.minX
        while(startX%nx != 0):
            startX = startX - 1


        if(distance_intervalleY >= 800):
            ny=60
        elif(distance_intervalleY >= 600):
            ny=50
        elif(distance_intervalleY >= 500):
            ny=40
        elif(distance_intervalleY >= 400):
            ny=30
        elif(distance_intervalleY >= 191):
            ny=20
        else:
            ny=10
            
        startY = self.maxY
        while(startY%ny != 0):
            startY+=1
        endX = self.maxX
        endY = self.minY
        if(startY<0):
            startY=0
        elif(self.minY>0):
            endY = 0
        if(startX >0):
            startX = 0
        elif(self.maxX <0):
            endX = 0

        self.tracerGraphe(nx, ny, startX, startY, endX, endY)
        previous_x = None
        previous_y = None
        for i in range(len(self.x)):
            x_remis = self.x[i]
            while(x_remis%30 != 0):
                x_remis -= 1
            if(self.x[i] < 0):
                x = 20 + (int(abs(startX)-abs(self.x[i]))*30/nx)
            else:
                x = 20 + int((abs(startX) + self.x[i])*30/nx)

            y_remis = self.y[i]
            while(x_remis%30 != 0):
                y_remis += 1
            if(self.y[i] > 0):
                y = 20 + int((startY - self.y[i])*30/ny)
            else:
                y = 20 + int((abs(startY) + abs(self.y[i]))*30/ny)
            print(x, y)
            self.canvas.create_rectangle(x-2, y-2, x+2, y+2, fill="red")
            if(previous_x != None):
                self.canvas.create_line(previous_x, previous_y, x, y, fill="red")
            previous_x = x
            previous_y = y
            

        
    def tracerGraphe(self, nx, ny, startX, startY, endX, endY):
        i = startX
        j=20
        while(i<=endX):
            self.canvas.create_text(j, int(abs(startY)*30/ny) + 20, text=str(i))
            j+=30
            i+=nx
        self.canvas.create_line(20, int(30*abs(startY)/ny)+10, j, int(30*abs(startY)/ny)+10)
        self.canvas.create_text(j+10, int(30*abs(startY)/ny)+10, text=self.nom_x, fill="blue")
        i = startY
        j = 20
        self.canvas.create_text(int(abs(startX)*30/nx)+15, 5, text=self.nom_y, fill="blue")
        while(i>=endY):
            if(i<100 and i > -100):
                self.canvas.create_text(int(abs(startX)*30/nx)+20, j, text=str(i))
                i-=ny
                j+=30
            else:
                self.canvas.create_text(int(abs(startX)*30/nx)+25, j, text=str(i))
                i-=ny
                j+=30
        self.canvas.create_line((int(30*abs(startX)/nx))+15, 20, int(30*abs(startX)/nx)+15, j)








