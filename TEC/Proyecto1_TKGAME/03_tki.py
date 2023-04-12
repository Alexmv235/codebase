from tkinter import *
import os
import time
def cargarImagen(nombre):
    ruta=os.path.join('d:/amv/Documents/AlexPython/TEC/Tkinter/'+nombre)
    imagen = PhotoImage(file=ruta)
    return imagen


class Ventana_Principal:
    def __init__(self,master):
        v= IntVar()
        self.canvas = Canvas(master,width=500,height=300,highlightthickness=0,relief='ridge')
        self.canvas.place(x=0,y=0)
        self.canvas.focus_set()

        self.label_Nom = Label(self.canvas, text="Nombre: ", font= ("Times New Roman",10),fg="#2196f3",pady=40)
        self.label_Nom.place(x=150, y=30, width=100, height=30)

        self.entrada_nombre = Entry(self.canvas)
        self.entrada_nombre.place(x=250, y=30, width=100, height=30)

        self.button_mostrar = Button(self.canvas, text="Mostrar mi nombre", command= self.mostrar_nombre, bg= "pink")
        self.button_mostrar.place(x=200, y=80, width=150, height=30)

        self.miNombre = Label(self.canvas, text="", font= ("Times New Roman",10),fg="#2196f3",pady=40)
        self.miNombre.place(x=200, y=130, width=100, height=30)

        self.canvas.bind("<KeyPress>", self.keydown)

        self.cuadrado = Canvas(master,width=10, height=10, bg="#050789")
        self.cuadrado.place(x=30,y=150)

        self.logo_python = cargarImagen("python.gif").subsample(10,10)
        self.label_logo =  Label(self.canvas, image=self.logo_python)
        self.label_logo.place(x=0,y=0,width=50, height=50)

        self.check1 = Checkbutton(self.canvas, text="Male")
        self.check1.place(x=200, y=180)

        self.check2 = Checkbutton(self.canvas, text="Female")
        self.check2.place(x=200, y=200)

        self.radio1 = Radiobutton(self.canvas, text="one", variable=v, value=1)
        self.radio1.place(x=400, y=170)

        self.radio2 = Radiobutton(self.canvas, text="two", variable=v, value=2)
        self.radio2.place(x=400, y=200)


    def mostrar_nombre(self):
        nomb=self.entrada_nombre.get()
        self.miNombre['text']=nomb
    def tecla_oprimida(self,event):
        print ("se oprimio en", event.x, event.y)
        self.animar_cuadrado(event.x,event.y)
        self.miNombre['text'] =str(event.x) +","+str(event.y)  
    def keydown(self,e):
        print ('down', e.keysym)
    
    def animar_cuadrado(self, posicionx, posiciony):
        self.cuadrado = Canvas(self.canvas, width=10, height=10, bg="#050789")
        self.cuadrado.place(x=posicionx,y=posiciony)
        Window.update()
        time.sleep(0.1)
        posiciony +=10
        if posiciony <290:
            self.cuadrado1 = Canvas(self.canvas, width=10, height=10)
            self.cuadrado1.place(x=posicionx,y=posiciony-10)
            self.animar_cuadrado(posicionx,posiciony)
    

Window=Tk()
ventana_principal=Ventana_Principal(Window)
Window.title("Hello World Alex")
Window.minsize(500,300)
Window.mainloop()

