from tkinter import *

def keydown(e):
    print ('down', e.keysym)

root = Tk()
frame = Frame(root, width=100, height=100)
frame.bind("<KeyPress>", keydown)
frame.pack()
frame.focus_set()
root.mainloop()
