
class FileRepo:
    def __init__(self, x, y, tmps):
        """cette classe prend en parametre une liste de coordonées et de temps pour les 
        passer au format csv sous forme de tableau"""
        self.x = x
        self.y = y
        self.tmps = tmps
    
    def transform2csv(self, file_name, adress):
        """cette méthode transforme les données au format csv, pour cela elle commence par 
        créer un nouveau fichier csv, puis ecrit le haut du tableau et avec une boucle
        va parcourir les données pour les ecrire petit à petit"""
        with open(adress + "/" + file_name, "w", encoding = "utf-8") as f:
            f.write(f"x; y; temps;\n")
            for i in range(len(self.x)):
                f.write(f"{self.x[i]}; {self.y[i]}; {self.tmps[i]};\n")
    


