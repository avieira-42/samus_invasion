 # Samus Invasion

Samus Invasion is a game I made on my time at 42 school with their own graphics library (minilibx-linux). This game wouldn't be possible without my two friends Rafael (https://github.com/therappha) and Gabriel (https://github.com/larocqueg). If it weren't for them creating one of the best side scroller approaches to the 42 project, so_long, I wouldn't ask for help and I wouldn't be able to understand how to be able to make the game I'm presenting here. The game consists of a simple side scroller visually inspired on pixel art games like metroid and blasphemous. As you can tell, I used samus sprite from metroid and, less obvious, I heavily copied blasphemous's penitent one movement on a character that I created on my own. All the pixel art was created by me aside from samus sprite.

To play the game you just need to run the make command and use the map.ber inside maps. The mechanics are for now a infinite jump(space or W) and an attack(S or down_arrow) when on air, and left(A or left_arrow) and right(D or right_arrow) when running, attacking or jumping. You must catch all the towels to be teleported away, and when you either die or finish the game, you may use Enter key to retry. Whenever you wanna quit you can use Esc or the cross at the right upper corner.

I will try and keep updating the game. In case you have ideas or want to contribbute, you can send my a message through email (vieiramendesalex@gmail.com) or through slack (avieira-42) in case you're at 42 school anywhere in the world. I hope you enjoy and thank you for trying my little game.

![samus_invasion](https://github.com/user-attachments/assets/4d92d82f-8124-421f-a547-138b22a2f557)

---

# How to install (Only Linux)

Compile the code:

# How to install

Compile the code:
```bash
make game
```
Play the game:
```bash
./game maps/map.ber
```
