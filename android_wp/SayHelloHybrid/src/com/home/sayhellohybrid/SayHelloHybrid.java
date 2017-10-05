package com.home.sayhellohybrid;

import android.app.Activity;
import android.content.DialogInterface.OnClickListener;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class SayHelloHybrid extends Activity {
	@Override
	public void onCreate(Bundle savedInstanceState) {
	super.onCreate(savedInstanceState);
	setContentView(R.layout.main);
	Button greetingButton
	=(Button)findViewById(R.id.greeting_button);
	greetingButton.setOnClickListener(new Toaster());
	}
	private class Toaster implements android.view.View.OnClickListener {
	
		public void onClick(View clickedButton) {
				String greetingText = getString(R.string.greeting_text);
				Toast tempMessage =
				Toast.makeText(SayHelloHybrid.this,
				greetingText,
				Toast.LENGTH_SHORT);
				tempMessage.show();
	}
 }
}
	