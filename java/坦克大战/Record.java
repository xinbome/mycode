package Tank;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;
import javax.imageio.ImageIO;
import java.math.*;


class Record//���þ�̬��Ա������Ŀ����ʹ���߳��£����ݲ�����
{
	private static int foenum=3;
	private static int mynum=1;
	public static int getFoenum()
	{
		return foenum;
	}
	public static int getMynum()
	{
		return mynum;
	}
	/*public static void setFoenum(int foenum)
	{
		Record.foenum=foenum;
	}
	public static void setMynum(int mynum)
	{
		Record.mynum=mynum;
	}
	*/
	public static void hitfoe()
	{
		foenum--;
	}
	public static void hitmy()
	{
		mynum--;
	}
}