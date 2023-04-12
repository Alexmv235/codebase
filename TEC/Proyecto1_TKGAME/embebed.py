import tkinter as tk
import pygame
 
pygame.init()
 
pwbr_power = 0
pwbr_duration = 0
pwbr_scrn_refresh = 0
pwbr_elps_time = 0
pwbr_ttl_sec = 0
 
pwbr_fcharged = False
pwbr_overload = False   # Reactor overload status.
pwbr_status = None
 
 
class Application(tk.Frame):
    def __init__(self, master=None):
        tk.Frame.__init__(self, master)
        self.grid()
        self.createwidgets()
    # __init__() ---------------------------------------------------------------
 
 
    def _cmd_quit(self):
        """
        Terminates the Tkwindow.
        """
         
        global quit_loop
         
        self.master.destroy()
        quit_loop = True
    # _cmd_quit() --------------------------------------------------------------
 
     
    def createwidgets(self):
        """
        Creates the numerous widgets that make up the form.
        """
         
        global pwbr_power, pwbr_duration, pwbr_scrn_refresh, pwbr_elps_time
        global pwbr_ttl_sec
 
        global pwbr_fcharged, pwbr_overload, pwbr_status
 
        col_width = None
         
        pwbr_power += 1
        pwbr_duration += 0.15
        pwbr_elps_time += pwbr_duration
        pwbr_scrn_refresh = 0.333
        pwbr_ttl_sec += pwbr_elps_time
 
        pwbr_fcharged = False
        pwbr_overload = False   # Reactor overload status.
        pwbr_status = "Normal"
 
        if pwbr_elps_time > pwbr_scrn_refresh:
            pwbr_elps_time = 0
            pwbr_duration = 0
 
        caption_pwr = "Power: " + str(pwbr_power)
        caption_dur = "Duration: " + str(pwbr_duration)
        caption_rfrsh =  "Screen Refresh: " + str(pwbr_scrn_refresh)
        caption_etime = "Elapsed time: " + str(pwbr_elps_time)
        caption_ttl = "Total sec's: " + str(pwbr_ttl_sec)
 
        caption_fcharged = "Fully charged: " + str(pwbr_fcharged)
        caption_overload = "Reactor overloading: " + str(pwbr_overload)
        caption_status = "Power bar status: " + str(pwbr_status)
 
        caption_hint1 = "Press [Spacebar] to simulate firing phaser cannons."
        caption_hint2 = "Press [r] to initiate a reactor overload."
        caption_hint3 = "Press [Esc] to quit"
         
        self.lblpower = tk.Label(self, text=caption_pwr, fg="black")
        self.lblduration = tk.Label(self, text=caption_dur, fg="black")
        self.lblrefreshrate = tk.Label(self, text=caption_rfrsh, fg="black")
        self.lbletime = tk.Label(self, text=caption_etime, fg="black")
        self.lbltotalsec = tk.Label(self, text=caption_ttl, fg="black")
 
        self.lblfcharged = tk.Label(self, text=caption_fcharged, fg="black")
        self.lbloverload = tk.Label(self, text=caption_overload, fg="black")
        self.lblstatus = tk.Label(self, text=caption_status, fg="black")
 
        self.lblhint1 = tk.Label(self, text=caption_hint1, fg="black")
        self.lblhint2 = tk.Label(self, text=caption_hint2, fg="black")
        self.lblhint3 = tk.Label(self, text=caption_hint3, fg="black")
         
        self.quitButton = tk.Button(self, text='Quit', command=self._cmd_quit)
         
        self.lblpower.grid(row=0, column=0, sticky="w")     #tk.W)
        self.lblduration.grid(row=1, column=0)
        self.lblrefreshrate.grid(row=2, column=0)
        self.lbletime.grid(row=3, column=0)
        self.lbltotalsec.grid(row=4, column=0)
 
        self.lblfcharged.grid(row=0, column=3)
        self.lbloverload.grid(row=1, column=3)
        self.lblstatus.grid(row=2, column=3)
 
        self.lblhint1.grid(row=6, column=2)
        self.lblhint2.grid(row=7, column=2)
        self.lblhint3.grid(row=8, column=2)
 
        # { Set the width for all the labels in column #1.
        col_width = 20
        self.lblpower["width"] = col_width
        self.lblduration["width"] = col_width
        self.lblrefreshrate["width"] = col_width
        self.lbletime["width"] = col_width
        self.lbltotalsec["width"] = col_width
        # }.
 
        # { Set the width for all the labels in column #3.
        col_width = 23
        self.lblfcharged["width"] = col_width
        self.lbloverload["width"] = col_width
        self.lblstatus["width"] = col_width
        # }.
 
        # { Set the text alignment for all the labels in column #1 & #2.
        self.lblpower["anchor"] = "w"
        self.lblduration["anchor"] = "w"
        self.lblrefreshrate["anchor"] = "w"
        self.lbletime["anchor"] = "w"
        self.lbltotalsec["anchor"] = "w"
 
        self.lblfcharged["anchor"] = "w"
        self.lbloverload["anchor"] = "w"
        self.lblstatus["anchor"] = "w"
        # }.
 
        # { Send the doc string information of the label object to the
        #   Python shell.
        print(help(self.lblpower))
        # }.
         
        self.quitButton.grid(row=6, column=3)
 
        # { Paint the image of the root / main TKinter window on the screen.
        self.update()
        # }.
 
        # { Set a timeout of a second to callback the routine
        #   update_info, so the labels are updated with the current (up to
        #   date) data values.
        self.after(1000, self.update_info)
        # }.
    # createwidgets() ----------------------------------------------------------
     
 
    def update_info(self):
        """
        Updates the status information in the tkinter window.
        """
         
        global pwbr_power, pwbr_duration, pwbr_scrn_refresh, pwbr_elps_time
        global pwbr_ttl_sec
         
        pwbr_power += 1
        pwbr_duration += 0.15
        pwbr_elps_time += pwbr_duration
        pwbr_scrn_refresh = 0.333
        pwbr_ttl_sec += pwbr_elps_time
 
        if pwbr_elps_time > pwbr_scrn_refresh:
            pwbr_elps_time = 0
            pwbr_duration = 0
 
        caption_pwr = "Power: " + str(pwbr_power)
        caption_dur = "Duration: " + str(pwbr_duration)
        caption_rfrsh =  "Screen Refresh: " + str(pwbr_scrn_refresh)
        caption_etime = "Elapsed time: " + str(pwbr_elps_time)
        caption_ttl = "Total sec's: " + str(pwbr_ttl_sec)
 
        self.lblpower.config(text=caption_pwr)
        self.lblduration["text"] = caption_dur
        self.lblrefreshrate.config(text=caption_rfrsh)
        self.lbletime.config(text=caption_etime)
        self.lbltotalsec.config(text=caption_ttl)
 
        self.after(1000, self.update_info)
    # update_info() ----------------------------------------------------------
# Application() ----------------------------------------------------------------
 
 
pygame.display.set_mode((640, 480))
 
app = Application()
app.master.title("Power Bar")
#app.mainloop()
 
 
 
 
quit_loop = False
while quit_loop is not True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:  # If user clicked close
            quit_loop = True  # Flag that we are done so we exit this loop
        elif event.type == pygame.MOUSEBUTTONUP:
            pass
        elif event.type == pygame.constants.KEYDOWN:
            if event.key == pygame.constants.K_ESCAPE:
                quit_loop = True
                break
            elif event.key == pygame.constants.K_LEFT:
                kbd["left"] = True
            elif event.key == pygame.constants.K_RIGHT:
                kbd["right"] = True
            elif event.key == pygame.constants.K_UP:
                kbd["up"] = True
            elif event.key == pygame.constants.K_DOWN:
                kbd["down"] = True
            elif event.key == pygame.constants.K_SPACE:  # Fire.
                kbd["fire"] = True
            elif event.key == pygame.constants.K_LCTRL:  # Thrust.
                kbd["thrust"] = True
            elif event.key == pygame.constants.K_r:
                kbd["overload"] = True
        elif event.type == pygame.constants.KEYUP:
            if event.key == pygame.constants.K_LEFT:
                kbd["left"] = False
            elif event.key == pygame.constants.K_RIGHT:
                kbd["right"] = False
            elif event.key == pygame.constants.K_UP:
                kbd["up"] = False
            elif event.key == pygame.constants.K_DOWN:
                kbd["down"] = False
            elif event.key == pygame.constants.K_SPACE:  # Fire.
                kbd["fire"] = False
            elif event.key == pygame.constants.K_LCTRL:  # Thrust.
                kbd["thrust"] = False
            elif event.key == pygame.constants.K_r:
                kbd["overload"] = False
            # end if
        # end if
    # end for loop
 
    # { Paint some graphics on the screen.
    #   ...
    # }.
    pygame.display.flip()
    app.master.update()
# end while loop
 
pygame.quit()