package Tank;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import javax.swing.JPanel;

class Welcome extends JPanel implements Runnable//这是欢迎界面
{
	int times=0;
	public void paint(Graphics g)
	{
		super.paint(g);
		g.fillRect(0, 0, 400, 300);
		
		if(times%2==0)//每隔固定时间刷新
		{
			g.setColor(Color.yellow);		
		    Font myFont=new Font("华文行楷",Font.BOLD,38);
		    g.setFont(myFont);
		    g.drawString("坦克大战", 140, 140);			
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