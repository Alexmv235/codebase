from tkinter import *
import os
def cargarImagen(nombre):
    ruta=os.path.join(nombre)
    imagen = PhotoImage(file=ruta)
    return imagen

class Ventana_Principal:
    
    #Funcion con los elementos visuales de la pantalla principal
    def __init__(self,master):
        self.pplace=[10,100]

        self.canvas = Canvas(master,highlightthickness=0,relief='ridge',background="black")
        self.canvas.pack(side="top", expand=True, fill='both')
        self.canvas.focus_set()
        

        self.img=cargarImagen("space2.gif").zoom(3)
        self.bgimage =Label(self.canvas,image=self.img)
        self.bgimage.pack(expand=True,)

        self.button_mostrar = Button(self.canvas, text="Salir", command= Window.quit, bg= "white")
        self.button_mostrar.place(x=10, y=10, width=150, height=30)
        self.ss=cargarImagen("space-ship.png").subsample(8)
        self.perso = Label(self.canvas,width=60, height=60, image=self.ss)
        self.perso.place(x=self.pplace[0],y=self.pplace[1])

        self.canvas.bind("<KeyPress>", self.tecla_oprimida)

    def tecla_oprimida(self,evento):
        #print ("se oprimio en", event.x, event.y)
        if evento.keysym=="Right":
            #print('tecla derecha')
            self.pplace[0]+=20
            self.perso.place(x=self.pplace[0],y=self.pplace[1])
        elif evento.keysym=="Left":
            self.pplace[0]+=-10
            self.perso.place(x=self.pplace[0],y=self.pplace[1])
        elif evento.keysym=="Up":
            self.pplace[1]+=-10
            self.perso.place(x=self.pplace[0],y=self.pplace[1])
        elif evento.keysym=="Down":
            self.pplace[1]+=10
            self.perso.place(x=self.pplace[0],y=self.pplace[1])
        elif evento.keysym=="Down" and evento.keysym=='Right':
            self.pplace[1]+=10
            self.place[0]+=10
            self.perso.place(x=self.pplace[0],y=self.pplace[1])
        else:
            self.perso.place(x=self.pplace[0],y=self.pplace[1])
    
            
        

Window=Tk()
ventana_principal=Ventana_Principal(Window)
Window.title("prueba1")
Window.minsize(600,600)
Window.attributes('-fullscreen', True)
Window.resizable(False,False)
Window.mainloop()