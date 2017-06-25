package Tank;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;
import javax.imageio.ImageIO;
import java.math.*;

class FoeTank extends Tank implements Runnable//敌方坦克类 继承Runnables实现多线程
{
    Vector<Bullet>fbu=new Vector<Bullet>();
    int speed=4;
	int time=0;
	public FoeTank(int x,int y)
	{
		super(x,y);
	}
	
	public void run()
	{
		while(true)
		{
			switch(this.direction)
			{
			case 0:
				for(int i=0;i<30;i++)//朝一个方向走的时间为30*50=1.5s，防止在原地抖动
				{
					try{
						Thread.sleep(50);
					}catch(Exception e){}
					if(y>0)
					{
						y-=speed;
					}
				}
				break;
			case 1:
				for(int i=0;i<30;i++)
				{
					try{
						Thread.sleep(50);
					}catch(Exception e){}	
					if(x>0)//防止坦克出边界
					{
					x-=speed;
					}
				}
				break;
			case 2:
				for(int i=0;i<30;i++)
				{
					try{
						Thread.sleep(50);
					}catch(Exception e){}	
					if(y<250)
					{
					y+=speed;
					}
				}
				break;
			case 3:
				for(int i=0;i<30;i++)
				{
					try{
						Thread.sleep(50);
					}catch(Exception e){}	
					if(x<360)
					{
					x+=speed;
					}
				}
				break;
			}
			this.direction=(int)(Math.random()*4);
			if(this.life==false)
			{
				break;
			}
            this.time++;
			
			if(time%2==0)//防止敌方坦克一连串的发射子弹
			{
				if(life)
				{
					if(fbu.size()<5)
					{
						Bullet bu=null;
						
						switch(direction)
						{
						case 0:
							bu=new Bullet(x+10,y,0);
							fbu.add(bu);
							break;
						case 1:
							bu=new Bullet(x,y+10,1);
							fbu.add(bu);
							break;
						case 2:
							bu=new Bullet(x+10,y+30,2);
							fbu.add(bu);
							break;
						case 3:
							bu=new Bullet(x+30,y+10,3);
							fbu.add(bu);
							break;
						}
						Thread t5=new Thread(bu);
						t5.start();
				   }
				}
			}
		}
	}
	
}