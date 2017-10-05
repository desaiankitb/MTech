package com.home.javalayoutdemo;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;



public class SayHelloJava extends Activity {
	@Override
	public void onCreate(Bundle savedInstanceState) {
			super.onCreate(savedInstanceState);
			String appName = "SayHello Application";
			String windowText =
					"Press the button below to receive " +
					"a friendly greeting from Android.";
			String buttonLabel = "Show Greeting";
			LinearLayout mainWindow = new LinearLayout(this);
			mainWindow.setOrientation(LinearLayout.VERTICAL);
			setTitle(appName);
			TextView label = new TextView(this);
			label.setText(windowText);
			mainWindow.addView(label);
			Button greetingButton = new Button(this);
			greetingButton.setText(buttonLabel);
			greetingButton.setOnClickListener(new Toaster());
			mainWindow.addView(greetingButton);
			setContentView(mainWindow);
	}
	private class Toaster implements  android.view.View.OnClickListener {
		@Override 
		public void onClick(View clickedButton) {
			String greetingText = "Hello from Android!";
			Toast tempMessage =
					Toast.makeText(SayHelloJava.this,
					greetingText,
					Toast.LENGTH_SHORT);
					tempMessage.show();
			}

		
	}
}
/*public class SayHelloJava extends Activity {
    // Called when the activity is first created. 
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
    }
}*/