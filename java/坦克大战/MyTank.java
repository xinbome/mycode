package Tank;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;
import javax.imageio.ImageIO;
import java.math.*;
import java.util.Vector;

class MyTank extends Tank//我的坦克
{
    Vector<Bullet>s=new Vector<Bullet>();
	public MyTank(int x,int y)
	{
		super(x,y);//调用父类的构造函数
	}
	Bullet bu=null;
	public void shoot()
	{
		switch(this.direction)
		{
		case 0:
			bu=new Bullet(x+10,y,0);
			s.add(bu);
			break;
		case 1:
			bu=new Bullet(x,y+10,1);
			s.add(bu);
			break;
		case 2:
			bu=new Bullet(x+10,y+30,2);
			s.add(bu);
			break;
		case 3:			
			bu=new Bullet(x+30,y+10,3);
		    s.add(bu);
			break;			
		}
		Thread t4=new Thread(bu);
		t4.start();
	}
	
	public void up()
	{
		if(y>0)
		{
			y-=speed;
		}
	}
	public void left()
	{
		if(x>0)//防止坦克出边界
		{
		x-=speed;
		}
	}
	public void down() 
	{
		if(y<250)
		{
		y+=speed;
		}
	}
	public void right()
	{
		if(x<360)
		{
		x+=speed;
		}
	}
}