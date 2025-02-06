#pragma once
#include <wx/wx.h>
#include <vector>
class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

private:

	// Declare methods that are only called once when application is opened
	void SetupControls();
	void SetupSizers();
	void AddNumpadButtons();

	// Declare methods that are called multiple times
	void ConcatenateNumber(std::string inputString);
	void UpdateDisplay();
	void Calculate();

	// Declare methods that are executed on events (like button presses)
	void OnButton1Clicked(wxCommandEvent& evt);
	void OnButton2Clicked(wxCommandEvent& evt);
	void OnButton3Clicked(wxCommandEvent& evt);
	void OnButton4Clicked(wxCommandEvent& evt);
	void OnButton5Clicked(wxCommandEvent& evt);
	void OnButton6Clicked(wxCommandEvent& evt);
	void OnButton7Clicked(wxCommandEvent& evt);
	void OnButton8Clicked(wxCommandEvent& evt);
	void OnButton9Clicked(wxCommandEvent& evt);
	void OnButton0Clicked(wxCommandEvent& evt);
	void OnButtonPercentClicked(wxCommandEvent& evt);
	void OnButtonCEClicked(wxCommandEvent& evt);
	void OnButtonCClicked(wxCommandEvent& evt);
	void OnButtonBackSpaceClicked(wxCommandEvent& evt);
	void OnButtonRecipricalClicked(wxCommandEvent& evt);
	void OnButtonSquareClicked(wxCommandEvent& evt);
	void OnButtonSQRTClicked(wxCommandEvent& evt);
	void OnButtonDivisionClicked(wxCommandEvent& evt);
	void OnButtonMulClicked(wxCommandEvent& evt);
	void OnButtonSubClicked(wxCommandEvent& evt);
	void OnButtonAddClicked(wxCommandEvent& evt);
	void OnButtonEqualsClicked(wxCommandEvent& evt);
	void OnButtonNegateClicked(wxCommandEvent& evt);
	void OnButtonDecimalClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();

	// Declare variables used in GUI
	wxPanel* panel;
	wxStaticText* headlineText;
	wxString calculatorDisplayedText;
	wxStaticText* calculatorDisplay;
	std::vector<wxButton*> buttons; 

	// Declare variables used in calculations/display
	double currentNum;
	double oldNum;
	std::string currentNumStr = "";
	std::string operationStr = "";
	bool IsJustCalculated = true;
	bool IsDivByZero = false;

	// Declare enum for button IDs
	enum IDs {
		BUTTON1_ID = 2,
		BUTTON2_ID = 3,
		BUTTON3_ID = 4,
		BUTTON4_ID = 5,
		BUTTON5_ID = 6,
		BUTTON6_ID = 7,
		BUTTON7_ID = 8,
		BUTTON8_ID = 9,
		BUTTON9_ID = 10,
		BUTTON0_ID = 11,
		BUTTONPERCENT_ID = 12,
		BUTTONCE_ID = 14,
		BUTTONC_ID = 15,
		BUTTONBACKSPACE_ID = 16,
		BUTTONRECIPRICAL_ID = 17,
		BUTTONSQUARE_ID = 18,
		BUTTONSQRT_ID = 19,
		BUTTONDIVISION_ID = 20,
		BUTTONMUL_ID = 21,
		BUTTONSUB_ID = 22,
		BUTTONADD_ID = 23,
		BUTTONEQUALS_ID = 24,
		BUTTONNEGATE_ID = 25,
		BUTTONDECIMAL_ID = 26

	};

};

