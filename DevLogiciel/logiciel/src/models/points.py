
class point:
    def __init__(self, x, y, timer):
        """La classe point possède trois arguments, x et y sont les coordonées de ce dernier,
        timer represente la seconde de la vidéo sur laquelle le point a été placé."""
        self.x = x
        self.y = y
        self.timer = timer
    
    def get_coordonees(self):
        """Cette méthode renvoie les coordonées x et y du point"""
        return self.x, self.y
    
    def modifier_coordonees(self, x, y):
        """Cette méthode prend en argument des coordonées qui remplaceront ceux du point."""
        self.x = x
        self.y = y

    def get_timer(self):
        """Cette méthode renvoie le timer du point"""
        return self.timer
    
    def modifier_timer(self, timer):
        """Cette méthode prend en argument un timer qui remplacera celui du point."""
        self.timer = timer
