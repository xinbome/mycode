package Tank;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;
import javax.imageio.ImageIO;

class MyPanel extends JPanel implements KeyListener,Runnable//�̳�JPanel �� �����������������̹��
{
	MyTank mt=null;
	Vector<FoeTank> ftk=new Vector<FoeTank>();//arraylist��֧�ֶ��̣߳�vector֧��
   
	
	int tknum=3;
	

	
	public MyPanel()
	{
		mt=new MyTank(142,232);
		for(int i=0;i<tknum;i++)
		{
			FoeTank foe=new FoeTank((i)*181+5,0);
			foe.setDirection(2);
			Thread t2=new Thread(foe);//��������̹���߳�
			t2.start();
			ftk.add(foe);
			Bullet bu=new Bullet(foe.x+10,foe.y+30,2);
			Thread t3=new Thread(bu);
			t3.start();
		}

	}
	public void paint(Graphics g)//���Ǹ���JPanel����ķ�����paint��������1��������2���ڴ�С�����仯3����repaint����ʱ�Զ�����
	{
		
		super.paint(g);
		g.fillRect(0, 0, 400, 300);//����̹�˵Ļ����Ĭ���Ǻ�ɫ
		if(mt.life)
		{
		this.drawTank(mt.getX(),mt.getY(),g,0,mt.getDirection());//�����Լ���̹��
		}
		for(int i=0;i<ftk.size();i++)
		{
			FoeTank ft=ftk.get(i);
			if(ftk.get(i).life)
			{
		
			this.drawTank(ftk.get(i).getX(),ftk.get(i).getY(), g, 1, ftk.get(i).direction);
			for(int j=0;j<ft.fbu.size();j++)//�������ڵз����ӵ������
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
			
			Bullet bu=mt.s.get(i);//ʵ������
			if(bu!=null&&bu.life==true)//�������߽�ʱ���ӵ�����ֵΪfalse��
			{
				g.setColor(Color.white);
				g.fill3DRect(bu.x, bu.y, 3, 3, false);
			}
			if(bu.life==false)//ɾ������ֵΪ�ٵ��ӵ�
			{
				mt.s.remove(bu);
			}
		}
		//̹�˵�ͳ��
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
		Font f=new Font("���Ĳ���",Font.BOLD,20);
		g.setFont(f);
		g.drawString("�������̹������", 410, 40);
	}
	public void drawTank(int x,int y,Graphics g,int kind,int direction)//��̹�˵ĺ�����Graphics���ʱ���Ҫ�����������������newһ������ô�����������ʶ����ˣ�֮ǰ�����þͰ׷���
	{
		
		switch(kind)
		{
		   case 0://�ҵ�̹��
			   g.setColor(Color.yellow);
			   break;
		   case 1://���˵�̹��
			   g.setColor(Color.green);
			   break;
		}
		switch(direction)
		{
		case 0://��Ͳ���ϵ�̹��
			g.fill3DRect(x, y, 5, 30,false);//��ߵľ���
			g.fill3DRect(x+15,y , 5, 30,false);//�ұߵľ���
			g.fill3DRect(x+5,y+5 , 10, 20,false);//�м�ľ���
			g.fillOval(x+5, y+10, 10, 10);//���ĵ�Բ
			g.drawLine(x+10, y+15, x+10, y-3);//��Ϊ��Ͳ��ֱ��
			break;
		case 1://��Ͳ�����̹��
			g.fill3DRect(x, y, 30, 5,false);
			g.fill3DRect(x, y+15, 30, 5, false);
			g.fill3DRect(x+5, y+5, 20, 10, false);
			g.fillOval(x+10, y+5, 10, 10);
			g.drawLine(x+15, y+10, x-3, y+10);
			break;
		case 2://��Ͳ���µ�̹��
			g.fill3DRect(x, y, 5, 30,false);
			g.fill3DRect(x+15,y , 5, 30,false);
			g.fill3DRect(x+5,y+5 , 10, 20,false);
			g.fillOval(x+5, y+10, 10, 10);
			g.drawLine(x+10, y+15, x+10, y+33);
			break;
		case 3://��Ͳ���ҵ�̹��
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
		while(true)//���100�������ػ棬��ֹ��Ϸ����ռ��ϵͳ��Դ
		{
			try{
				Thread.sleep(100);}
			catch(Exception e){}
			hitmine();
			hitfoe();
			this.repaint();
			
		}
	}

	public void hitfoe()//�ӵ����е���̹��
	{
		for(int i=0;i<mt.s.size();i++)//�������е��ӵ�
		{
			Bullet bu=mt.s.get(i);
			if(bu.life)
			{
				for(int j=0;j<ftk.size();j++)//�������еĵз�̹�ˣ��ж��Ƿ��ӵ�����̹��
				{
					FoeTank foe=ftk.get(j);
					if(foe.life)
					{
						this.hittank(bu,foe,0);//���û���̹�˺���
					}
				}
			}
		}
	}
    public void hitmine()//����̹�˻����ҷ�̹��
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
	public void hittank(Bullet bu,Tank tk,int kind)//�жϺ���,foetank��mytank������������ת��Ϊtank���ͣ�ʵ���˶�̬
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
			if(this.mt.s.size()<4)//�������4���ӵ�
			{
				this.mt.shoot();
			}
		}
		
		this.repaint();//�ƶ��ı����ǲ��ϵ��ػ�
	}
	
}