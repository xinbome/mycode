package Tank;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;
import javax.imageio.ImageIO;

public class Tankrun extends JFrame implements ActionListener {//�����ؼ��ļ���  ����������
	MyPanel mp=null;
	Welcome we=null;
	JMenuBar cdl=null;
	JMenu cd1=null;
	JMenuItem cdx1=null;
	public static void main(String[] args) {
		Tankrun t1=new Tankrun();
	}
	
	public Tankrun()//���캯����������
	{

		cdl=new JMenuBar();
		cd1 =new JMenu("��Ϸ(G)");
		cd1.setMnemonic('G');
		cdx1 =new JMenuItem("��ʼ(N)");
		cdx1.addActionListener(this);
		cdx1.setActionCommand("newGame");
		cd1.add(cdx1);
		cdl.add(cd1);
		we=new Welcome();
		Thread t=new Thread(we);
		t.start();
		this.setJMenuBar(cdl);	
		this.add(we);
		this.setTitle("̹�˴�ս");
		this.setSize(600,500);//���ڴ�С
		this.setLocation(300,280);//��ʼʱ���ڵ�λ��
		this.setResizable(false);//���û��ı䲻�˴���
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//ÿ�ιر�ʱ��������
		this.setVisible(true);

	}
	
	public void actionPerformed(ActionEvent e)
	{
		if(e.getActionCommand().equals("newGame"))
		{
			mp=new MyPanel();
			this.remove(we);//ɾ�������
			this.add(mp);
			this.addKeyListener(mp);//����mp���
			Thread t=new Thread(mp);
			t.start();
			this.setVisible(true);//��ʾ��ǰ���
		}
	}
}







