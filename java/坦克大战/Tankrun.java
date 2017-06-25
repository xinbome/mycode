package Tank;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;
import javax.imageio.ImageIO;

public class Tankrun extends JFrame implements ActionListener {//对面板控件的监听  程序的入口类
	MyPanel mp=null;
	Welcome we=null;
	JMenuBar cdl=null;
	JMenu cd1=null;
	JMenuItem cdx1=null;
	public static void main(String[] args) {
		Tankrun t1=new Tankrun();
	}
	
	public Tankrun()//构造函数里添加组件
	{

		cdl=new JMenuBar();
		cd1 =new JMenu("游戏(G)");
		cd1.setMnemonic('G');
		cdx1 =new JMenuItem("开始(N)");
		cdx1.addActionListener(this);
		cdx1.setActionCommand("newGame");
		cd1.add(cdx1);
		cdl.add(cd1);
		we=new Welcome();
		Thread t=new Thread(we);
		t.start();
		this.setJMenuBar(cdl);	
		this.add(we);
		this.setTitle("坦克大战");
		this.setSize(600,500);//窗口大小
		this.setLocation(300,280);//开始时窗口的位置
		this.setResizable(false);//让用户改变不了窗口
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//每次关闭时结束进程
		this.setVisible(true);

	}
	
	public void actionPerformed(ActionEvent e)
	{
		if(e.getActionCommand().equals("newGame"))
		{
			mp=new MyPanel();
			this.remove(we);//删除旧面板
			this.add(mp);
			this.addKeyListener(mp);//监听mp面板
			Thread t=new Thread(mp);
			t.start();
			this.setVisible(true);//显示当前面板
		}
	}
}







