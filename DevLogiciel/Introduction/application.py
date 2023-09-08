from tkinter import *
from random import randint

class Application():

    def __init__(self):

        self.fenetre = Tk()
        self.fenetre.title("My thermometer")
        self.label = Label(self.fenetre, text=str(randint(0, 10))+ "°C", width='20', height = '5', font = ('Arial', 25), bg='ivory')
        self.label.pack(side=TOP, padx=5, pady=5)

        Button(self.fenetre, text ='+1', command = self.increase).pack(side=LEFT, padx=5, pady=5)
        Button(self.fenetre, text ='+10', command = self.increase2).pack(side=LEFT, padx=5, pady=5)
        Button(self.fenetre, text ='-1', command = self.decrease).pack(side=RIGHT, padx=5, pady=5)
        Button(self.fenetre, text ='-10', command = self.decrease2).pack(side=RIGHT, padx=5, pady=5)
        Button(self.fenetre, text ='Celcius', command = self.celsius).pack(pady=5)
        Button(self.fenetre, text ='Farenheight', command = self.farenheight).pack(pady=5)
        Button(self.fenetre, text ='Kelvin', command = self.kelvin).pack(pady=5)

        
        self.fenetre.mainloop()

    def increase(self):
        value = int(self.label['text'][:-2]) + 1
        unit = self.label['text'][-2:]
        self.label.config( text = str( value ) + unit)
        if value >= 20:
            self.label.config(bg = 'red')
        if 5 < value < 20:
            self.label.config(bg = 'ivory')

    def increase2(self):
        value = int(self.label['text'][:-2]) + 10 
        unit = self.label['text'][-2:]
        self.label.config( text = str( value ) + unit)
        if value >= 20:
            self.label.config(bg = 'red')
        if 5 < value < 20:
            self.label.config(bg = 'ivory')


    def decrease(self):
        value = int(self.label['text'][:-2]) - 1
        unit = self.label['text'][-2:]
        self.label.config( text = str( value  ) + unit)
        if 5 < value < 20:
            self.label.config(bg = 'ivory')
        elif value <= 5:
             self.label.config(bg = 'blue')

    
    def decrease2(self):
        value = int(self.label['text'][:-2]) - 10
        unit = self.label['text'][-2:]
        self.label.config( text = str( value  ) + unit)
        if 5 < value < 20:
            self.label.config(bg = 'ivory')
        elif value <= 5:
             self.label.config(bg = 'blue')

    def celsius(self):
        if self.label['text'][-2:] == "°F":
            value =int((int(self.label['text'][:-2])-32) * 5/9)
        else:
            value =int(int(self.label['text'][:-2])-273)           
        unit = "°C"
        self.label.config( text = str(value) + unit)

    def farenheight(self):
        if self.label['text'][-2:] == "°C":
            value = int(int(self.label['text'][:-2])*9/5 + 32)
        else:
            value = int((int(self.label['text'][:-2])-273)*9/5 + 32)

        unit = "°F"
        self.label.config( text = str(value) + unit)
    
    def kelvin(self):
        if self.label['text'][-2:] == "°C":
            value = int(int(self.label['text'][:-2]) + 273)
        else:
            value =int((int(self.label['text'][:-2])-32) * 5/9 + 273) 
        unit = "°K"
        self.label.config( text = str(value) + unit)


if __name__ == '__main__':
    app = Application()