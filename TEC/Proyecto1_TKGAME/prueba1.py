from tkinter import *
import os
def cargarImagen(nombre):
    ruta=os.path.join(nombre)
    imagen = PhotoImage(file=ruta)
    return imagen

class Ventana_Principal:
    
    #Funcion con los elementos visuales de la pantalla principal
    def __init__(self,master):
        self.v= IntVar()
        self.print=False

        self.canvas = Canvas(master,highlightthickness=0,relief='ridge',background="black")
        self.canvas.pack(side="top", expand=True, fill='both')
        

        self.img=cargarImagen("space2.gif").zoom(3)
        self.bgimage =Label(self.canvas,image=self.img)
        self.bgimage.pack(expand=True,)

        self.button_mostrar = Button(self.canvas, text="Salir", command= Window.quit, bg= "white")
        self.button_mostrar.place(x=10, y=10, width=150, height=30)

        

Window=Tk()
ventana_principal=Ventana_Principal(Window)
Window.title("prueba1")
Window.minsize(600,600)
Window.attributes('-fullscreen', True)
Window.resizable(False,False)
Window.mainloop()