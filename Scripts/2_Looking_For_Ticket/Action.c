Action()
{
	
lr_start_transaction("UC_02_looking_for_ticket");

	MainPage();

		lr_think_time(2);

	Login();
	
		lr_think_time(2);
		
	Itinerary();
	
		lr_think_time(2);

	Flights();

		lr_think_time(2);	

	FindFlight_rnd();
	
		lr_think_time(2);
	
	ChooseTicket_rnd();
	
		lr_think_time(2);
	
	Itinerary();
	
		lr_think_time(2);
	
	SignOff();
	
lr_end_transaction("UC_02_looking_for_ticket", LR_AUTO);

	return 0;
}