/* Imports the java.util package classes. */
import java.util.Date;
import java.util.StringTokenizer;
/* Imports the java.io package classes. */
import java.io.File;
import java.io.RandomAccessFile;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
/* Imports the javax.swing package classes. */
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import java.awt.Font;
/* Imports the java.awt.event package classes. */
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
/* Imports the java.nio package classes. */
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.FileLock;
/*
The class ActionPerform - This class implements the core functionality of the Editor. 
This class provides the implementation of methods that are called in the Editor class.
Fields: 
   value - Contains the return value of the showDialog() method.
   option - Contains 0 or 1 value.
   content - Contains the content of a file.
   name - Contains the file name.
   word - Contains the word that to be searched.
   str - Represents a string variable.
Methods:
   newFile() - This method opens a new file.
   openFile() - This method calls the method to open an existing file.
   saveFile() - This method calls the method to save the existing file.
   saveAsFile() - This method calls the method to save the new file.
   printFile() - This method enables you to print the file.
   exitFile() - This method closes the application.
   cutFile() - This method cuts the selected text.
   copyFile() - This method copies the selected text. 
   pasteFile() - This method pastes the cut or copied text.
   dateTime() - This method inserts date and time in the file.
   exLockFile() - This method locks the file with exclusive lock.
   shLockFile() - This method locks the file with share lock.
   findFile() - This method finds a specified word in the file.
   wrapFile() - This method wraps the text line in the file.
   selectAllFile() - This method selects all the contents of the file.
   aboutFile() -This method opens the help file. 
   colorFile() - This method opens a Color dialog box.
   fontFile() - This method opens a Font dialog box.
   open() - This method opens a new file.
   save() - This method saves the existing file.
   saveAs() - This method saves the newly created file.
*/
public class ActionPerform
{
   int value; 
   int option; 
   String content = null; 
   String name = null; 
   String word; 
   String str;
   /* Creates an instance of the JFileChooser() class. */
   JFileChooser jfc = new JFileChooser("."); 
   /* Creates an instance of the Editor class. */ 
   public Editor ed; 
   /* Creates an object of the FontClass() method. */
   public FontClass font = new FontClass();
   /* Creates an object of the ColorClass() method. */
   public ColorClass cc = new ColorClass();
   /* Creates an object of the Help() method. */
   public Help h = new Help();
   /* Creates an object of the PrintClass() method. */
   public PrintClass pc;
   /* 
   Defines default constructor of the ActionPerform class. 
   */
   public ActionPerform(Editor ed)
   {
      this.ed = ed;
   }
   /* Implementation of the newFile() method. */
    public void newFile()
   {
      if(!ed.area.getText().equals("") && !ed.area.getText().equals(content))
      {
         if(name == null)
         {
            /* Shows a Confirm dialog box. */
            option = JOptionPane.showConfirmDialog(null,"Do you want to save the file?");
            if(option == 0)
            {
               /* Calls the saveAs() method. */
                saveAs();
               /* Sets the text area to be NULL. */ 
                ed.area.setText("");
             }
             
             if(option == 1)
             {
                ed.area.setText("");
             }
          }
          else
          {
            /* Shows a Confirm dialog box. */
            option = JOptionPane.showConfirmDialog(null,"Do you want to save the file?");
            if(option == 0)
            {
               /* Calls the save() method. */
               save();
               ed.area.setText("");
             }
             if(option == 1)
             {
                ed.area.setText("");
             }
          }
       }
       else
       {
          ed.area.setText("");
       }
      /* Sets the title of the main window. */
       ed.setTitle("Untitled - Text Editor");
      }
      /* Implementation of openFile() method. */
      public void openFile()
      {
      if(!ed.area.getText().equals("") && !ed.area.getText().equals(content))
      {
         if(name == null)
         {
            /* Shows a Confirm dialog box. */
            option = JOptionPane.showConfirmDialog(null,"Do you want to save the file?");
            if(option == 0)
            {
               /* Calls the saveAs() method. */
               saveAs();
               open();
            }
            if(option == 1)
            {
               open();
            }
          }
          else
          {
            /* Shows a Confirm dialog box. */
            option = JOptionPane.showConfirmDialog(null,"Do you want to save the file?");
            if(option == 0)
            {
               /* Calls the save() method. */
               save();
               /* Calls the open() method. */
               open();
             }
             if(option == 1)
            {
               /* Calls the save() method. */
               open();
             }
          }
       }
       else
       {
         /* Calls the open() method. */
          open();
       }
    }
   /* Implementation of the saveFile() method. */
    public void saveFile()
    {
       if(name == null)
       {
         /* Calls the saveAs() method. */
          saveAs(); 
       }
       else
       {
         /* Calls the save() method. */
          save();
       }
    }
   /* Implementation of the saveAsFile() method. */
    public void saveAsFile()
    {
      /* Calls the saveAs() method. */
       saveAs(); 
    }
   /* Implementation of printFile() method. */
    public void printFile()
    {
         /* 
         Creates an instance of the PrintClass that inputs the ed.area component and ed 
         object of the Editor class as parameters. 
         */
          pc = new PrintClass(ed.area, ed);
         /* Calls the print() method. */
          pc.print();
    }
   /* Implementation of the exitFile() method. */
    public void exitFile()
    {
      if(!ed.area.getText().equals("") && !ed.area.getText().equals(content))
       {
          if(name == null)
         {
            /* Shows a Confirm dialog box. */
            option = JOptionPane.showConfirmDialog(null,"Do you want to save the file?");
            if(option == 0)
            {
               /* Calls the saveAs() method. */
               saveAs();
               /* Closes the main application. */
               System.exit(0);
            }
            if(option == 1)
            {
               System.exit(0);
            }
         }
         else
         {
            /* Shows a Confirm dialog box. */
            option = JOptionPane.showConfirmDialog(null,"Do you want to save the file?");
            if(option == 0)
            {
               /* Calls the save() method. */
               save();
               System.exit(0);
            }
            if(option == 1)
            {
               System.exit(0);
            }
         }
      }
      else
      {
          System.exit(0);
      }
   }
   /* Implementation of the cutFile() method. */
    public void cutFile()
    {
      /* Cuts the selected area from the text area. */
       ed.area.cut();
    }
      /* Implementation of the copyFile() method. */
      public void copyFile()
      {
         /* Copies the selected area from the text area. */
         ed.area.copy();
      }
      /* Implementation of the pasteFile() method. */
      public void pasteFile()
      {
         /* Pastes the cut/copied area to the text area. */
          ed.area.paste();
      }
      /* Implementation of the selectAllFile() method. */
      public void selectAllFile()
      {
         /* Selects all the content of the text area. */
          ed.area.selectAll();
       }
      /* Implementation of the findFile() method. */
       public void findFile()
       {
          try
         {
            /* Shows a word input dialog box. */
            word = JOptionPane.showInputDialog("Type the word to find");
            while(ed.area.getText().indexOf(word) == -1)
            {
            /* Shows a message dialog box. */
            JOptionPane.showMessageDialog(null,"Word not found!","No match",JOptionPane.WARNING_MESSAGE);
            word = JOptionPane.showInputDialog(" Type the word to find");
       }
       /* Selects the word in the text area. */ 
       ed.area.select(ed.area.getText().indexOf(word),
       ed.area.getText().indexOf(word) + word.length());
       }
       catch(Exception ex)
       {
         /* Showss an error message dialog box. */
         JOptionPane.showMessageDialog
         (null,"Search canceled","Abourted",JOptionPane.WARNING_MESSAGE);
       }
    }
   /* Implementation of the dateTime() method. */
    public void dateTime()
    {
      /* Creates an object of the Date class. */
       Date d = new Date();
      /* Converts time to string and display it. */
       String str = d.toLocaleString(); 
      /* Appends the date and time in the text area. */
       ed.area.append(str);
    }
   /* Implementation of the fontFile() method. */
    public void fontFile()
    {
      /* Shows the Font dialog box. */
      font.setVisible(true); 
      font.pack(); 
      /* Calls the getOk() method of FontClass. */
      font.getOk().addActionListener(new ActionListener()
      {
         public void actionPerformed(ActionEvent ae)
         {
            /* 
            Sets the font name, size, and style of the file text. 
            */ 
            ed.area.setFont(font.font());
            font.label.setFont(new Font("Arial",Font.PLAIN,15));
            font.setVisible(false);
         }
      }); 
      /* Calls the getCancel() method of FontClass. */
      font.getCancel().addActionListener(new ActionListener()
      {
         public void actionPerformed(ActionEvent ae)
         {
            /* Hides the Font dialog box. */
            font.label.setFont(new Font("Arial",Font.PLAIN,15));
            font.setVisible(false);
         }
      });
   }
   /* Implementation of the colorFile() method. */
   public void colorFile()
   {
      /* Shows the Color dialog box. */
      cc.setVisible(true); 
      cc.pack(); 
      /* Calls the getOk() method of ColorClass. */
      cc.getOk().addActionListener(new ActionListener()
      {
         public void actionPerformed(ActionEvent ae)
         {
            /* Sets the color of the file text. */ 
            ed.area.setForeground(cc.color());
            cc.setVisible(false);
         }
      }); 
      /* Calls the getCancel() method of ColorClass. */
      cc.getCancel().addActionListener(new ActionListener()
      {
         public void actionPerformed(ActionEvent ae)
         {
            /* Hides the Color dialog box. */
            cc.setVisible(false);
         }
      });
   }
   /* Implementation of the wrapFile() method. */
   public void wrapFile()
   {
      if(ed.wordWrap.getState() == true)
      {
         /* Sets the line and word wrap style to TRUE. */
         ed.area.setLineWrap(true);
         ed.area.setWrapStyleWord(true);
      }
      else
      {
         /* Sets the line and word wrap style to FALSE. */
         ed.area.setLineWrap(false);
         ed.area.setWrapStyleWord(false);
      }
   }
   /* Implementation of the aboutFile() method. */
   public void aboutFile()
   {
      /* Shows the Help dialog box. */
      h.setVisible(true);
      /* Calls the getOk() method of Help. */
      h.getOk().addActionListener(new ActionListener()
      {
      public void actionPerformed(ActionEvent ae)
      {
         /* Hides the Help dialog box. */
         h.setVisible(false);
      }
   }); 
   }
   /* Implementation of exLockFile() method. */
   public void exLockFile()
   {
      try 
      {
         /* Creates an object of the File class. */
         File file = new File(str);
         /* Creates an object of the RandomAccessFile class. */
         RandomAccessFile raf = new RandomAccessFile(file, "rw"); 
         /* Creates an object of the FileChannel class. */
         FileChannel channel = raf.getChannel(); 
         if(ed.exclusiveLock.getState() == true)
         {
            /* 
            Uses the file channel to create an exclusive lock on the file. 
            The lock() method blocks until it can retrieve the lock. 
            */
            FileLock lock = channel.lock(0, Long.MAX_VALUE, false);
         }
         else if(ed.exclusiveLock.getState() == false)
         {
            /* Closes the channel. */
            channel.close(); 
         }
      } 
      catch (Exception e) 
      {
         System.out.println("Error: " + e); 
      } 
   }
   /* Implementation of the shLockFile() method. */
   public void shLockFile()
   {
      try 
      {
         /* Creates an object of the File class. */
         File file = new File(str);
         /* Create an object of the RandomAccessFile class. */
         RandomAccessFile raf = new RandomAccessFile(file, "rw"); 
         /* Creates an object of the FileChannel class. */
         FileChannel channel = raf.getChannel();
         if(ed.shareLock.getState() == true)
         {
            /* 
            Uses the file channel to create a share lock on the file. 
            The lock() method blocks until it can retrieve the lock. 
            */
            FileLock lock = channel.lock(0, Long.MAX_VALUE, true);
         }
         else if(ed.shareLock.getState() == false)
         {
            /* Closes the channel. */
            channel.close();
         }
      }
      catch (Exception e) 
      {
         System.out.println("Error:" + e);
      }
   }
   /* Implementation of open() method. */
   public void open()
   {
      value = jfc.showOpenDialog(ed); 
      if(value == JFileChooser.APPROVE_OPTION)
      {
         ed.area.setText(null);
         ed.exclusiveLock.setEnabled(true);
         ed.shareLock.setEnabled(true);
         try
         {
            /* Gets the file name. */
            name = jfc.getSelectedFile().getPath();
            /* Creates an object of FileInputStream class. */
            FileInputStream fin = new FileInputStream(jfc.getSelectedFile());
            /* 
            Creates a channel and get the channel from the FileInputStream 
            */
            FileChannel fchan = fin.getChannel();
            /* Stores the size of file in long variable */
            long fsize = fchan.size();
            /* 
            Creates an object of the Bytebuffer class and allocate the size of this byte buffer 
            */
            ByteBuffer buff = ByteBuffer.allocate((int)fsize);
            /* Reads the bytes from channel to byte buffer*/
            fchan.read(buff);
            /* Rewinds the byte buffer */ 
            buff.rewind();
            /* 
            Returns the byte buffer into an array and converts this array into string 
            */
            String str = new String(buff.array());
            /* Appends this string to the text area */
            ed.area.append(str);
            content = ed.area.getText();
            /* Closes the channel */
            fchan.close();
            /* Closes the input stream */
            fin.close();
         }
         catch(IOException ioe)
         {
            System.err.println("I/O Error on Open");
         }
         /* Sets the title of the main window */
         ed.setTitle(jfc.getSelectedFile().getAbsolutePath()+ " - Text Editor");
         str = jfc.getSelectedFile().getAbsolutePath();
      }
   }
   /* Implementation of save() method. */
   public void save()
   {
      if(value == JFileChooser.APPROVE_OPTION)
      {
         try
         {
            /* Creates an object of FileOutputStream class */
            FileOutputStream fout = new FileOutputStream(jfc.getSelectedFile());
            /* Creates an object of PrintWriter class */
            PrintWriter pw = new PrintWriter(fout);
            content = ed.area.getText();
            /* Creates an object of StringTokenizer class */
            StringTokenizer st=new StringTokenizer(content,System.getProperty("line.separator"));
            while(st.hasMoreTokens())
            {
               pw.println(st.nextToken());
            }
            /* Closes print writer */
            pw.close();
            /* Closes output stream */
            fout.close();
         }
         catch(IOException ioe)
         {
            System.err.println("I/O Error on Save");
         }
         /* Sets the title of the window */
         ed.setTitle(jfc.getSelectedFile().getName()+ " - Text Editor");
         str = jfc.getSelectedFile().getAbsolutePath();
      }
   }
   /* Implementation of saveAs() method. */
   public void saveAs()
   {
      jfc.setDialogTitle("Save As"); 
      value = jfc.showSaveDialog(ed);
      if(value == JFileChooser.APPROVE_OPTION)
      {
         try
         {
            /* Creates an object of FileOutputStream class */
            FileOutputStream fout = new FileOutputStream(jfc.getSelectedFile() + ".txt");
            /* Creates an object of PrintWriter class */
            PrintWriter pw = new PrintWriter(fout);
            content = ed.area.getText();
            name = jfc.getSelectedFile().getPath();
            /* Creates an object of StringTokenizer class */
            StringTokenizer st=new StringTokenizer(content,System.getProperty("line.separator"));
            while(st.hasMoreTokens())
            {
               pw.println(st.nextToken());
            }
            /* Closes print writer */
            pw.close();
            /* Closes output stream */
            fout.close();
         }
         catch(IOException ioe)
         {
            System.err.println ("I/O Error on Save");
         }
         /* Sets the title of the window */
         ed.setTitle(jfc.getSelectedFile().getAbsolutePath() + " - Text Editor");
         str = jfc.getSelectedFile().getAbsolutePath();
      } 
   }
}

