package Tank;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;
import javax.imageio.ImageIO;

class MyPanel extends JPanel implements KeyListener,Runnable//继承JPanel 类 在这个面板容器里，运行坦克
{
	MyTank mt=null;
	Vector<FoeTank> ftk=new Vector<FoeTank>();//arraylist不支持多线程，vector支持
   
	
	int tknum=3;
	

	
	public MyPanel()
	{
		mt=new MyTank(142,232);
		for(int i=0;i<tknum;i++)
		{
			FoeTank foe=new FoeTank((i)*181+5,0);
			foe.setDirection(2);
			Thread t2=new Thread(foe);//启动敌人坦克线程
			t2.start();
			ftk.add(foe);
			Bullet bu=new Bullet(foe.x+10,foe.y+30,2);
			Thread t3=new Thread(bu);
			t3.start();
		}

	}
	public void paint(Graphics g)//覆盖父类JPanel里面的方法，paint方法会在1启动程序2窗口大小发生变化3运行repaint函数时自动调用
	{
		
		super.paint(g);
		g.fillRect(0, 0, 400, 300);//设置坦克的活动区域，默认是黑色
		if(mt.life)
		{
		this.drawTank(mt.getX(),mt.getY(),g,0,mt.getDirection());//绘制自己的坦克
		}
		for(int i=0;i<ftk.size();i++)
		{
			FoeTank ft=ftk.get(i);
			if(ftk.get(i).life)
			{
		
			this.drawTank(ftk.get(i).getX(),ftk.get(i).getY(), g, 1, ftk.get(i).direction);
			for(int j=0;j<ft.fbu.size();j++)//将容器内敌方的子弹都射出
			{
				Bullet ftbu=ft.fbu.get(j);
				if(ftbu.life)
				{
					g.setColor(Color.white);
					g.fill3DRect(ftbu.x,ftbu.y,3,3,false);
				}
				else
				{
					
					ft.fbu.remove(ftbu);
				}
			}
			}
		}
		for(int i=0;i<mt.s.size();i++)
		{
			
			Bullet bu=mt.s.get(i);//实现连发
			if(bu!=null&&bu.life==true)//当超出边界时，子弹生命值为false了
			{
				g.setColor(Color.white);
				g.fill3DRect(bu.x, bu.y, 3, 3, false);
			}
			if(bu.life==false)//删除生命值为假的子弹
			{
				mt.s.remove(bu);
			}
		}
		//坦克的统计
		this.drawTank(80,330, g, 0, 0);
		g.setColor(Color.black);
		g.drawString(Record.getMynum()+"",116,350);
		this.drawTank(150, 330, g, 1, 0);
		g.setColor(Color.black);
		g.drawString(Record.getFoenum()+"",186,350);
	    this.drawTank(450, 86, g, 1,0);
	    g.setColor(Color.black);
		g.drawString((3-Record.getFoenum())+"",486,107);
		g.setColor(Color.black);
		Font f=new Font("华文彩云",Font.BOLD,20);
		g.setFont(f);
		g.drawString("您消灭的坦克总数", 410, 40);
	}
	public void drawTank(int x,int y,Graphics g,int kind,int direction)//画坦克的函数，Graphics画笔必须要传进来，如果在里面new一个，那么就是两个画笔对象了，之前的设置就白费了
	{
		
		switch(kind)
		{
		   case 0://我的坦克
			   g.setColor(Color.yellow);
			   break;
		   case 1://敌人的坦克
			   g.setColor(Color.green);
			   break;
		}
		switch(direction)
		{
		case 0://炮筒冲上的坦克
			g.fill3DRect(x, y, 5, 30,false);//左边的矩形
			g.fill3DRect(x+15,y , 5, 30,false);//右边的矩形
			g.fill3DRect(x+5,y+5 , 10, 20,false);//中间的矩形
			g.fillOval(x+5, y+10, 10, 10);//中心的圆
			g.drawLine(x+10, y+15, x+10, y-3);//作为炮筒的直线
			break;
		case 1://炮筒冲左的坦克
			g.fill3DRect(x, y, 30, 5,false);
			g.fill3DRect(x, y+15, 30, 5, false);
			g.fill3DRect(x+5, y+5, 20, 10, false);
			g.fillOval(x+10, y+5, 10, 10);
			g.drawLine(x+15, y+10, x-3, y+10);
			break;
		case 2://炮筒冲下的坦克
			g.fill3DRect(x, y, 5, 30,false);
			g.fill3DRect(x+15,y , 5, 30,false);
			g.fill3DRect(x+5,y+5 , 10, 20,false);
			g.fillOval(x+5, y+10, 10, 10);
			g.drawLine(x+10, y+15, x+10, y+33);
			break;
		case 3://炮筒冲右的坦克
			g.fill3DRect(x, y, 30, 5,false);
			g.fill3DRect(x, y+15, 30, 5, false);
			g.fill3DRect(x+5, y+5, 20, 10, false);
			g.fillOval(x+10, y+5, 10, 10);
			g.drawLine(x+15, y+10, x+33, y+10);
			break;			
		}
		this.repaint();
	}
	public void run()
	{
		while(true)//间隔100毫秒再重绘，防止游戏过度占用系统资源
		{
			try{
				Thread.sleep(100);}
			catch(Exception e){}
			hitmine();
			hitfoe();
			this.repaint();
			
		}
	}

	public void hitfoe()//子弹击中电脑坦克
	{
		for(int i=0;i<mt.s.size();i++)//遍历所有的子弹
		{
			Bullet bu=mt.s.get(i);
			if(bu.life)
			{
				for(int j=0;j<ftk.size();j++)//遍历所有的敌方坦克，判断是否子弹击中坦克
				{
					FoeTank foe=ftk.get(j);
					if(foe.life)
					{
						this.hittank(bu,foe,0);//调用击中坦克函数
					}
				}
			}
		}
	}
    public void hitmine()//电脑坦克击中我方坦克
    {
		for(int i=0;i<ftk.size();i++)
		{
			FoeTank ft=ftk.get(i);
			
			for(int j=0;j<ft.fbu.size();j++)
			{
				Bullet bu=ft.fbu.get(j);
				if(mt.life)
				{
					this.hittank(bu,mt,1);					
				}				
			}
		}
    }
	public void hittank(Bullet bu,Tank tk,int kind)//判断函数,foetank和mytank都在这里向上转型为tank类型，实现了多态
	{
		switch(tk.direction)
		{
		case 0:
		case 2:
			if(bu.x>tk.x && bu.x<tk.x+20 && bu.y>tk.y && bu.y<tk.y+30)
			{
				bu.life=false;
				tk.life=false;
				if(kind==0)
				{
					Record.hitfoe();
				}
				if(kind==1)
				{
					Record.hitmy();
				}
			}
			break;
		case 1:
		case 3:
			if(bu.x>tk.x && bu.x<tk.x+30 && bu.y>tk.y && bu.y<tk.y+20)
			{
				bu.life=false;
				tk.life=false;
				if(kind==0)
				{
					Record.hitfoe();
				}
				if(kind==1)
				{
					Record.hitmy();
				}
			}			
		}
	}

	public void keyTyped(KeyEvent e){}
	public void keyReleased(KeyEvent e){}
	public void keyPressed(KeyEvent e)
	{
		if(e.getKeyCode()==KeyEvent.VK_W)
		{
			this.mt.setDirection(0);
			this.mt.up();
			
		}else if(e.getKeyCode()==KeyEvent.VK_A)
		{
			this.mt.setDirection(1);
			this.mt.left();
		}else if(e.getKeyCode()==KeyEvent.VK_S)
		{
			this.mt.setDirection(2);
			this.mt.down();
		}else if(e.getKeyCode()==KeyEvent.VK_D)
		{
			this.mt.setDirection(3);
			this.mt.right();
		}	
	    if(e.getKeyCode()==KeyEvent.VK_J)
		{
			if(this.mt.s.size()<4)//最多连发4个子弹
			{
				this.mt.shoot();
			}
		}
		
		this.repaint();//移动的本质是不断的重绘
	}
	
}