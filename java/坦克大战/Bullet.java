package Tank;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;
import javax.imageio.ImageIO;
import java.math.*;

class Bullet implements Runnable //���ӵ���Ϊ�߳�
{
	int x;
	int y;
	int direction;
	int speed=6;
	boolean life=true;//�ӵ���������
	public Bullet(int x,int y,int direction)
	{
		this.x=x;
		this.y=y;
		this.direction=direction;
	}
    public void run()
    {
		while(true)//��ѭ������������ʱ�����ӵ�
		{
			try	{
				Thread.sleep(50);}//˯��ʱ�䣬��ֹ�ӵ�һ���ͳ�
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
			if(x<0||x>400||y<0||y>300)//ȷ���ӵ��ķ�Χ��������Ϸ�߽�
			{
				this.life=false;
				break;				
			}
		}
		
	}	
 }
