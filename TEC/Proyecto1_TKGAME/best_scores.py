from tkinter import *
from obener_scores import ordenar_lista, obtenerPunt, obtenerNomb


def best():
    class Best7:
        def __init__(self, master, puntajes, nombres):

            self.puntajes = puntajes
            self.nombres = nombres

            self.bg = PhotoImage(file="space2.gif").zoom(4, 4)

            # Create Canvas
            self.canvas = Canvas(master, width=1280,
                             height=715)

            self.canvas.pack(fill="both", expand=True)

            # Display image
            self.canvas.create_image(0, 0, image=self.bg,
                                 anchor="nw")

            # Add Text
            self.canvas.create_text(400, 15, text="Los Mejores Puntajes",font=(
                "Times New Roman", 24),fill="white")
            self.canvas.create_text(150, 50, text="Posicion",font=(
                "Times New Roman", 16),fill="white")
            self.canvas.create_text(250, 50, text="Nombre",font=(
                "Times New Roman", 16),fill="white")
            self.canvas.create_text(640, 50, text="Puntaje",font=(
                "Times New Roman", 16),fill="white")
           
            self.showResults()

        def showResults(self):
            return self.auxShw(self.puntajes, self.nombres, 80, 0)

        def auxShw(self, puntajes, nombres, posy, i):
            if puntajes != [] and i < 7 and i < len(puntajes):
                self.canvas.create_text(150, posy, text=str(i+1),font=(
                "Times New Roman", 16),fill="white")
                self.canvas.create_text(250, posy, text=nombres[i],font=(
                    "Times New Roman", 16),fill="white")
                self.canvas.create_text(640, posy, text=puntajes[i],font=(
                    "Times New Roman", 16),fill="white")

                self.auxShw(puntajes, nombres, posy+30, i+1)

    puntajes, nombres = ordenar_lista(obtenerPunt(), obtenerNomb())
    Window = Tk()
    ventana_principal = Best7(Window, puntajes, nombres)
    Window.title("Hello World Alex")
    Window.minsize(1280, 715)
    Window.mainloop()


