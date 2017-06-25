package Tank;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;
import javax.imageio.ImageIO;
import java.math.*;

class Bullet implements Runnable //把子弹作为线程
{
	int x;
	int y;
	int direction;
	int speed=6;
	boolean life=true;//子弹的生命期
	public Bullet(int x,int y,int direction)
	{
		this.x=x;
		this.y=y;
		this.direction=direction;
	}
    public void run()
    {
		while(true)//死循环，所以能随时发射子弹
		{
			try	{
				Thread.sleep(50);}//睡眠时间，防止子弹一按就出
			catch (Exception e) {}
			switch(direction)
			{
			case 0:
				y-=speed;
				break;
			case 1:
				x-=speed;
				break;
			case 2:
				y+=speed;
				break;
			case 3:
				x+=speed;
				break;
			}
			if(x<0||x>400||y<0||y>300)//确保子弹的范围不超出游戏边界
			{
				this.life=false;
				break;				
			}
		}
		
	}	
 }
