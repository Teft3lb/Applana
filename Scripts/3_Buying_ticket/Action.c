Action()
{
	
lr_start_transaction("UC_03_Buy_ticket");

	MainPage();

		lr_think_time(3.33);

	Login();
	
		lr_think_time(3.33);	

	Flights();

		lr_think_time(3.33);	

	FindFlight_rnd();	
	
		lr_think_time(3.33);
	
	ChooseTicket_rnd();
	
		lr_think_time(3.33);
		
	PaymentDetails();
	
		lr_think_time(3.33);
	
		
	//SignOff();

lr_end_transaction("UC_03_Buy_ticket",LR_AUTO);
	return 0;
}