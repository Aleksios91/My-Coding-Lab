from tkinter import *
from tkinter.ttk import *
import pygame

pygame.mixer.init()

#Sounds
lock_sound=pygame.mixer.Sound("C:\\Users\\ALEKSA\\Desktop\\Depository\\audio.mp3")
unlock_sound=pygame.mixer.Sound("C:\\Users\\ALEKSA\\Desktop\\Depository\\audio.mp3")
trunk_sound=pygame.mixer.Sound("C:\\Users\\ALEKSA\\Desktop\\Depository\\trunk.mp3")



def lock():
    
    lock_sound.play()
def unlock():
    
    unlock_sound.play()
def trunk():
    
    trunk_sound.play()

#Tkinter Display and Specs 
Window=Tk()
Window.geometry("1280x1024")
Window.title("Car Key")
icon=PhotoImage(file="C:\\Users\\ALEKSA\\Desktop\\Depository\\car key.png")
Window.iconphoto(True,icon)

#image
image = PhotoImage(file="C:\\Users\\ALEKSA\\Desktop\\Depository\\prime-sedan.png")
label = Label(Window, image=image)
label.place(anchor="center",relx=0.5, rely=0.2)

#Lock button
lock_button=Button(text="Lock",command=lock)
lock_button.place(anchor="center",relx=0.3,rely=0.9)
#Unlock button
unlock_button=Button(text="Unlock",command=unlock)
unlock_button.place(anchor="center",relx=0.5,rely=0.9)
#Trunk button
trunk_button=Button(text="Trunk",command=trunk)
trunk_button.place(anchor="center",relx=0.7,rely=0.9)
Window.mainloop()