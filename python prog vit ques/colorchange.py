import colorama
from colorama import Fore,Back,Style

colorama.init()
message='hi'
print (message)
print (Fore.RED+message)
print(Fore.BLUE+message)
print(Fore.RED+Back.YELLOW+message+Style.RESET_ALL)
