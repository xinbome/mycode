package Tank;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import javax.swing.JPanel;

class Welcome extends JPanel implements Runnable//���ǻ�ӭ����
{
	int times=0;
	public void paint(Graphics g)
	{
		super.paint(g);
		g.fillRect(0, 0, 400, 300);
		
		if(times%2==0)//ÿ���̶�ʱ��ˢ��
		{
			g.setColor(Color.yellow);		
		    Font myFont=new Font("�����п�",Font.BOLD,38);
		    g.setFont(myFont);
		    g.drawString("̹�˴�ս", 140, 140);			
		}		
	}
	public void run() 
	{
		while(true)
		{
			try 
	        {
	           Thread.sleep(600);}
	        catch (Exception e){}
			times++;
			this.repaint();
		}		
		
	}		
}