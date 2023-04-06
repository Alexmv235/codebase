from tkinter import *

class Ventana_Principal:
    
    #Funcion con los elementos visuales de la pantalla principal
    def __init__(self,master):
        self.v= IntVar()
        self.print=False

        
        self.canvas = Canvas(master,width=600,height=600,highlightthickness=0,relief='ridge',background="grey")
        self.canvas.place(x=0,y=0)
        
        img=PhotoImage(file="uno.jpg")
        self.bgimage =Label(self.canvas,image=img)
        self.bgimage.place(x=30,y=40)

        self.button_mostrar = Button(self.canvas, text="Salir", command= Window.quit, bg= "white")
        self.button_mostrar.place(x=170, y=160, width=150, height=30)

        

Window=Tk()
ventana_principal=Ventana_Principal(Window)
Window.title("prueba1")
Window.minsize(600,600)
Window.attributes('-alpha', True)
Window.resizable(False,False)
Window.mainloop()