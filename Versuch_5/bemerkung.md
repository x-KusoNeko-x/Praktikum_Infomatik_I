Achtung/注意:

1:
  bei "switch" muss immer hinter jede fall einmal "break" funktion ausfuehren, sonst macht das programm nach durchlaufen noch naechste fall./在使用“switch”型循环时，需要在每种情况（case）后进行一次“break”（如果你只需要程序运行一次），否则程序将会自动执行下一个情况。

2:
  delete cursor immer, nachdem die nicht mehr nuetzlich ist, sonst kann das zu bugs fuehren, wenn sie nochmal ein anderen cursor implementieren./应当在每一次使用完一个临时的cursor后，将这个临时的cursor删除，否则在下一次要定义一个同名指针是，很有可能导致程序故障
