import serial                                   
import pyautogui                                  

Arduino_Serial = serial.Serial('com6',9600)       
 
while 1:
    incoming_data = str (Arduino_Serial.readline())
    print "incoming_data"                           
     

    if 'next' in incoming_data:                    
        pyautogui.hotkey('ctrl', 'pgdn')           
        
    if 'previous' in incoming_data:                
        pyautogui.hotkey('ctrl', 'pgup')          

    if 'down' in incoming_data:                
        #pyautogui.press('down')                  
        pyautogui.scroll(-100) 
         
    if 'up' in incoming_data:                     
        #pyautogui.press('up')                      
        pyautogui.scroll(100)
        
    if 'change' in incoming_data:                  
        pyautogui.keyDown('alt')                 
        pyautogui.press('tab')
        pyautogui.keyUp('alt')
        
    incoming_data = "";                        
