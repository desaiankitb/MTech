/* Imports the java.net package class. */
import java.net.URL;
/* Imports javax.swing.undo package classes. */
import javax.swing.undo.UndoManager;
import javax.swing.undo.CannotUndoException;
import javax.swing.undo.CannotRedoException;
/* Imports javax.swing package classes. */
import javax.swing.JColorChooser;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JTextArea;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.UIManager;
import javax.swing.Action;
import javax.swing.KeyStroke;
import javax.swing.AbstractAction;
/* Imports java.awt package class. */
import java.awt.BorderLayout;
/* Imports java.awt.event package classes. */
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;
/* Imports javax.swing.event package classes. */
import javax.swing.event.UndoableEditListener;
import javax.swing.event.UndoableEditEvent;
/*
Class Editor - This class is the main class of the application. This class initializes 
the interface and loads all components like text area and menu bar on the main window.
Fields:
   menu - Creates the menu bar.
   file - Creates the File menu.
   edit - Creates the Edit menu.
   format - Creates the Format menu.
   lock - Creates the Lock menu.
   help - Creates the Help menu.
   newfile - Creates the New menu item.
   open - Creates the Open menu item.
   print - Creates the Print menu item.
   save - Creates the Save menu item.
   saveas - Creates the Save As menu item.
   exit - Creates the Open Exit item.
   cut - Creates the Cut menu item.
   copy - Creates the Copy menu item.
   paste - Creates the Paste menu item.
   find - Creates the Find menu item.
   selectAll - Creates the Select All menu tem.
   datetime - Creates the Date/Time menu item.
   font - Creates the Open Font item.
   color - Creates the Open Color item.
   about - Creates the Open Help item.
   area - Creates an object the JTextArea class that contains the file contents.
   panel - Creates the panel menu item that contains all the AWT and swing components.
   scrollpane - Creates an object of the JScrollPane class that is added to the text area.
   str - Creates the String object.
   wordWrap - Creates the Word Wrap menu item.
   exclusiveLock - Creates the Exclusive menu item.
   shareLock - Creates the Share menu item.
Methods:
   addWindowListener() - This method is called when end user clicks the window close button.
   actionPerformed() - This method is invoked when an end user selects any command from the menu bar.
   undoableEditHappened() - This method is called when an end user performs undo and redo operation.
   main() - This method creates the main window of the application and displays it.
*/
public class Editor extends JFrame implements ActionListener, UndoableEditListener, Runnable
{
   /* Creates an object of the ActionPerform class. */
   public ActionPerform action = new ActionPerform(this);
   /* Creates an object of the UndoManager class. */
   UndoManager undoManager = new UndoManager();
   /* Creates an instance of the UndoAction class. */
   UndoAction undoAction = new UndoAction();
   /* Creates an instance of the RedoAction class. */
   RedoAction redoAction = new RedoAction();
   /* Declares an object of the JMenuBar class. */
   JMenuBar menu;
   /* Declares objects of the JMenu class. */
   JMenu file;
   JMenu edit;
   JMenu format;
   JMenu lock;
   JMenu help;
   /* Declares objects of the JMenuItem class. */
   JMenuItem newfile;
   JMenuItem open;
   JMenuItem print;
   JMenuItem save;
   JMenuItem saveas;
   JMenuItem exit;
   JMenuItem cut;
   JMenuItem copy;
   JMenuItem paste;
   JMenuItem find;
   JMenuItem selectAll;
   JMenuItem datetime;
   JMenuItem font;
   JMenuItem color;
   JMenuItem about;
   /* Declares an object of the JTextArea class. */
   JTextArea area;
   /* Declares an object of the JPanel class. */
   JPanel panel;
   /* Declares an object of the JScrollPane class. */
   JScrollPane scrollpane;
   /* Declares an object of the String class. */
   String str;
   /* Declares objects of the JCheckBoxMenuItem class. */
   JCheckBoxMenuItem wordWrap;
   JCheckBoxMenuItem exclusiveLock;
   JCheckBoxMenuItem shareLock;
   /* Declares objects of the Thread class. */
   Thread t1;
   Thread t2;
   Thread t3;
   int act;
   /* Defines the constructor of the Editor class. */
   public Editor()
   {
      /* 
      Initializes the menu bar and sets the menu bar to the frame. 
      */
      menu = new JMenuBar();
      setJMenuBar(menu);
      setTitle("Text Editor");
      /* 
      Initializes the menu and adds the menus to the menu bar. 
      */
      file = new JMenu("File");
      menu.add(file);
      edit = new JMenu("Edit");
      menu.add(edit);
      format = new JMenu("Format");
      menu.add(format);
      lock = new JMenu("Locks");
      menu.add(lock);
      help = new JMenu("Help");
      menu.add(help);
      /* Sets the mnemonic to the menu. */
      file.setMnemonic('f');
      edit.setMnemonic('e');
      lock.setMnemonic('l');
      format.setMnemonic('o');
      help.setMnemonic('h');
      /*
      Initializes the menu items.
      Adds the menu item to the particular menu.
      Adds the action listener with each menu item.
      Sets accelerator to each menu item.
      */
      /* File->New */
      newfile = new JMenuItem("New");
      newfile.addActionListener(this);
      newfile.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_N, ActionEvent.CTRL_MASK));
      file.add(newfile);
      /* File->Open */
      open = new JMenuItem("Open...");
      open.addActionListener(this);
      open.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_O, ActionEvent.CTRL_MASK));
      file.add(open);
      /* File->Save */
      save = new JMenuItem("Save");
      save.addActionListener(this);
      save.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S, ActionEvent.CTRL_MASK));
      file.add(save);
      /* File->Save As */
      saveas = new JMenuItem("Save As...");
      saveas.addActionListener(this);
      file.add(saveas);
      /* File->Print */
      print = new JMenuItem("Print");
      print.addActionListener(this);
      print.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_P, ActionEvent.CTRL_MASK));
      file.add(print);
      /* File->Exit */
      exit = new JMenuItem("Exit");
      exit.addActionListener(this);
      exit.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_F4, ActionEvent.CTRL_MASK));
      file.add(exit);
      /* Inserts separators at the 4th and 6th positions. */
      file.insertSeparator(4);
      file.insertSeparator(6);
      /* Edit->Undo */
      edit.add(undoAction);
      /* Edit->Redo */
      edit.add(redoAction);
      /* Edit->Cut */
      cut = new JMenuItem("Cut");
      edit.add(cut);
      cut.addActionListener(this);
      cut.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_X, ActionEvent.CTRL_MASK));
      /* Edit->Copy */
      copy = new JMenuItem("Copy");
      edit.add(copy);
      copy.addActionListener(this);
      copy.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_C, ActionEvent.CTRL_MASK));
      /* Edit->Paste */
      paste = new JMenuItem("Paste");
      edit.add(paste);
      paste.addActionListener(this);
      paste.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_V, ActionEvent.CTRL_MASK));
      /* Edit->Find */
      find = new JMenuItem("Find");
      edit.add(find);
      find.addActionListener(this);
      find.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_F, ActionEvent.CTRL_MASK));
      /* Edit->Select All */
      selectAll = new JMenuItem("Select All");
      edit.add(selectAll);
      selectAll.addActionListener(this);
      selectAll.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_A, ActionEvent.CTRL_MASK));
      /* Edit->Date/Time */
      datetime = new JMenuItem("Date/Time");
      edit.add(datetime);
      datetime.addActionListener(this);
      datetime.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_F5, ActionEvent.CTRL_MASK));
      /* Inserts separators at the 2nd, 6th, and 9th positions. */
      edit.insertSeparator(2);
      edit.insertSeparator(6);
      edit.insertSeparator(9);
      /* Format->Font */
      font = new JMenuItem("Font");
      format.add(font);
      font.addActionListener(this);
      /* Format->Color */
      color = new JMenuItem("Color");
      format.add(color);
      color.addActionListener(this);
      /* Format->Word Wrap */
      wordWrap = new JCheckBoxMenuItem("Word Wrap");
      format.add(wordWrap);
      wordWrap.addActionListener(this);
      /* Lock->Exclusive Lock */
      exclusiveLock = new JCheckBoxMenuItem("Exclusive Lock");
      exclusiveLock.setEnabled(false);
      lock.add(exclusiveLock);
      exclusiveLock.addActionListener(this);
      /* Lock->Share Lock */
      shareLock = new JCheckBoxMenuItem("Share Lock");
      shareLock.setEnabled(false);
      lock.add(shareLock);
      shareLock.addActionListener(this);
      /* Help->Help Topics */ 
      about = new JMenuItem("Help Topics");
      help.add(about);
      about.addActionListener(this);
      /* Initializes the panel. */
      panel = new JPanel();
      /* Sets the panel layout as BorderLayout. */
      panel.setLayout(new BorderLayout());
      /* Adds the panel to the frame. */
      getContentPane().add(panel, BorderLayout.CENTER);
      /* Initializes the object of text area */ 
      area = new JTextArea(25, 65);
      /* 
      Adds UndoableEditListener to the area for undo and redo operations. 
      */
      area.getDocument().addUndoableEditListener(this);
      /* Sets line wrap to false. */ 
      area.setLineWrap(false);
      /* Sets word wrap style to false. */ 
      area.setWrapStyleWord(false);
      /* 
      Initializes the object of the Scrollpane class and adds the text area to the scroll pane. 
      */
      scrollpane = new JScrollPane(area);
      /* Adds the scroll pane to the panel. */
      panel.add(scrollpane);
      /* Sets default close operation to false. */ 
      setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
      /*
      addWindowListener - It contains a windowClosing() method.
      windowClosing: It is called when the user clicks the cancel button of the Window. 
      It closes the main window.
      Parameter: we- Represents an object of the WindowEvent class.
      Return Value: NA
      */
      addWindowListener(new WindowAdapter()
      {
         public void windowClosing(WindowEvent we)
         {
             System.exit(0);
          }
       }); 
      }
      /*
      undoableEditHappened() - This method is called when the user wants to perform undo/redo.
      Parameters: e – Represents an object of UndoableEditEvent class that contains 
      the details of the undo/redo events.
      Return Value: NA
      */
      public void undoableEditHappened(UndoableEditEvent e)
      {
         /* 
         Inserts an Edit at indexOfNextAdd and removes any old edits that were at indexOfNextAdd or later. 
         */
          undoManager.addEdit(e.getEdit());
         /* Calls the update() method to perform undo operations. */
          undoAction.update();
         /* Calls the update() method to perform redo operations. */
          redoAction.update();
      }
      /*
      actionPerformed() - This method is called when the end user selects any menu item from the menu bar.
      Parameters: ae – Represents an object of the ActionEvent class that contains the details of the event.
      Return Value: NA
      */
      public void actionPerformed(ActionEvent ae)
      {
         /* 
         This section is executed when the end user selects the File->New command to the menu bar.
         */
          if(ae.getSource() == newfile)
          {
            /* Calls the newFile() method. */
             exclusiveLock.setEnabled(false);
             shareLock.setEnabled(false);
             action.newFile();
          }
         /* 
         This section is executed when the end user selects the File->Open command to the menu bar.
         */
          else if(ae.getSource() == open)
          {
            /* Calls the openFile() method. */
             action.openFile();
          }
         
         /* 
         This section is executed when the end user selects the File->Save command to the menu bar.
         */
          else if(ae.getSource() == save)
          {
            /* Calls the saveFile() method. */
             action.saveFile();
          }
         /* 
         This section is executed when the end user selects the File->Save As command to the menu bar.
         */
          else if(ae.getSource() == saveas)
          {
            /* Calls the saveAsFile() method. */
             action.saveAsFile();
          }
         /* 
         This section is executed when the end user selects the File->Print command to the menu bar.
         */
          else if(ae.getSource() == print)
          {
            /* Calls the printFile() method. */
             act = 1;
             t1 = new Thread(this);
             t1.start();
          }
         /* 
         This section is executed when the end user selects the Edit->Exit command to the menu bar.
         */
          else if(ae.getSource() == exit)
          {
            /* Calls the exitFile() method. */
             action.exitFile();
          }
         /* 
         This section is executed when the end user selects the Edit->Cut command to the menu bar.
         */
          else if(ae.getSource() == cut)
          {
            /* Calls the cutFile() method. */
             action.cutFile();
          }
         /* 
         This section is executed when the end user selects the Edit->Copy command to the menu bar.
         */
          else if(ae.getSource() == copy)
          {
            /* Calls the copyFile() method. */
             action.copyFile();
          }
         /* 
         This section is executed when the end user selects the Edit->Paste command to the menu bar.
         */
          else if(ae.getSource() == paste)
          {
               /* Calls the pasteFile() method. */
                action.pasteFile();
          }
         /* 
         This section is executed when the end user selects the Edit->Date/Time command to the menu bar.
         */
          else if(ae.getSource() == datetime)
          {
            /* Calls the dateTime() method. */
             action.dateTime();
          }
         /* 
         This section is executed when the end user selects the Edit->Find command to the menu bar.
         */
          else if(ae.getSource() == find)
          {
            /* Calls the findFile() method. */
             action.findFile();
          }
         /* 
         This section is executed when the end user selects the Edit->Select All command to the menu bar.
         */
          else if(ae.getSource() == selectAll)
          {
            /* Calls the selectAllFile() method. */
             action.selectAllFile();
          }
         /* 
         This section is executed when the end user selects the Format->Font command to the menu bar.
         */
          else if(ae.getSource() == font)
          {
            /* Calls the fontFile() method. */
             action.fontFile();
          }
         /* 
         This section is executed when the end user selects the Format->Color command to the menu bar.
         */
          else if(ae.getSource() == color)
          {
            /* Calls the colorFile() method. */
             action.colorFile(); 
          }
         /* 
         This section is executed when the end user selects the Format->Word Wrap command to the menu bar.
         */
          else if(ae.getSource() == wordWrap)
          {
            /* Calls the warpFile() method. */
             action.wrapFile();
          }
         /* 
         This section is executed when the end user selects the Lock->Exclusive command to the menu bar.
         */
          else if(ae.getSource() == exclusiveLock)
          {
             act = 2;
             t2 = new Thread(this);
             t2.start();
          }
         /* 
         This section is executed when the end user selects the Lock->Share command to the menu bar.
         */
          else if(ae.getSource() == shareLock)
          {
             act = 3;
             t3 = new Thread(this);
             t3.start();
          }
         /* 
         This section is executed when the end user selects the Help->Help Topics command to the menu bar.
         */
          else if(ae.getSource() == about)
          {
            /* Calls the aboutFile() method. */
             action.aboutFile(); 
          } 
       }
       public void run()
       {
          if(act==1)
          {
             action.printFile();
       }
       else if(act==2)
       {
         /* Calls the exLockFile() method. */
          action.exLockFile();
       }
       else if(act==3)
       {
         /* Calls the shLockFile() method. */
          action.shLockFile();
       }
    }
   /*
   main() - This method creates the main window of the user interface and displays it.
   Parameters:
   args[] - Contains any command line arguments passed.
   Return Value: NA
   */
    public static void main(String args[])
    {
       try
       {
         /* 
         Initializes and sets the look and feel of the application to Windows look and feel. 
         */
         UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
       }
       catch(Exception e)
       {
         System.out.println("Unknown Look and Feel." + e); 
       }
      /* Creates an object of the Editor class. */
       Editor ed = new Editor();
      /* Sets the size of the main window. */
       ed.setSize(725, 460);
      /* Sets the visibility of the window to TRUE. */ 
       ed.setVisible(true);
      /* Displays the main window. */
       ed.show();
    }
   /*
   Class UndoAction - Extends the AbstractAction class to perform undo operations.
   Method:
   UndoAction() - Implements the default constructor of the UndoClass.
   actionPerformed() - Performs the action event.
   update() - Updates the change made by the end user. */
    class UndoAction extends AbstractAction
    {
      /* Defines the default constructor. */
       public UndoAction()
    {
       super("Undo");
       setEnabled(false);
    }
   /*
   actionPerformed() - This method is called when the end user select the Edit->Undo command from the menu bar.
   Parameters: e – Represent an object of the ActionEvent class that contains details of the event.
   Return Value: NA
   */
   public void actionPerformed(ActionEvent e)
    {
       try
       {
          undoManager.undo();
       }
       catch (Exception ex)
       {
         System.out.println("Error: " + ex);
       }
       update();
       redoAction.update();
    }
   /*
   update() - This method performs undo operations. 
   Parameters: NA
   Return Value: NA
   */
    protected void update()
    {
       if(undoManager.canUndo())
       {
            setEnabled(true);
            putValue("Undo", undoManager.getUndoPresentationName());
       }
       else
       {
         setEnabled(false);
         putValue(Action.NAME, "Undo");
       }
    }
 }
/*
Class UndoAction - Extends the AbstractAction class to perform redo operations.
Method:
RedoAction() - Implements the default constructor of UndoClass.
actionPerformed() - Performs the action event.
update() - Updates the changes made by the end user. 
*/
 class RedoAction extends AbstractAction
 {
   /* Defines the default constructor. */
    public RedoAction()
    {
       super("Redo");
       setEnabled(false);
    }
      /*
      actionPerformed() - This method is called when the end user selects the 
      Edit->Redo command from the menu bar.
      Parameters: e – Represents an object of the ActionEvent class that contains 
      the details of the event.
      Return Value: NA
      */
      public void actionPerformed(ActionEvent e)
      {
         try
         {
             undoManager.redo();
         }
          catch (Exception ex)
          {
            System.out.println("Error: " + ex);
          }
          update();
          undoAction.update();
       }
      /*
      update() - This method performs the redo operations. 
      Parameters: NA
      Return Value: NA
      */
      protected void update()
      {
          if(undoManager.canRedo())
          {
               setEnabled(true);
               putValue("Redo", undoManager.getRedoPresentationName());
          }
          else
          {
             setEnabled(false);
            putValue(Action.NAME, "Redo");
          }
       }
    }
}
