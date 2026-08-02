import pywhatkit as pwk

Phone_number = ""  # ✅ Phone number as a string
Message = "message sent using python"

pwk.sendwhatmsg(Phone_number, Message, 21, 31)  # ✅ Schedule message at 21:20 (9:20 PM)
