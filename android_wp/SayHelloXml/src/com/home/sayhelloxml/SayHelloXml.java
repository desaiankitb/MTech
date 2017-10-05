package com.home.sayhelloxml;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class SayHelloXml extends Activity {
	@Override
	public void onCreate(Bundle savedInstanceState) {
	super.onCreate(savedInstanceState);
	setContentView(R.layout.main);
	}
	public void showToast(View clickedButton) {
		String greetingText = getString(R.string.greeting_text);
		Toast tempMessage =
		Toast.makeText(this, greetingText,
		Toast.LENGTH_SHORT);
		tempMessage.show();
	}
}