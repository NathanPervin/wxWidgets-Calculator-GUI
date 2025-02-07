#include "MainFrame.h"
#include <wx/wx.h>
#include <vector>
#include <math.h> 
#include <string>
#include <cmath>  

// Declare the many events and assign each button press to its respective method
wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(BUTTON1_ID, MainFrame::OnButton1Clicked)
	EVT_BUTTON(BUTTON2_ID, MainFrame::OnButton2Clicked)
	EVT_BUTTON(BUTTON3_ID, MainFrame::OnButton3Clicked)
	EVT_BUTTON(BUTTON4_ID, MainFrame::OnButton4Clicked)
	EVT_BUTTON(BUTTON5_ID, MainFrame::OnButton5Clicked)
	EVT_BUTTON(BUTTON6_ID, MainFrame::OnButton6Clicked)
	EVT_BUTTON(BUTTON7_ID, MainFrame::OnButton7Clicked)
	EVT_BUTTON(BUTTON8_ID, MainFrame::OnButton8Clicked)
	EVT_BUTTON(BUTTON9_ID, MainFrame::OnButton9Clicked)
	EVT_BUTTON(BUTTON0_ID, MainFrame::OnButton0Clicked)

	EVT_BUTTON(BUTTONPERCENT_ID, MainFrame::OnButtonPercentClicked)
	EVT_BUTTON(BUTTONCE_ID, MainFrame::OnButtonCEClicked)
	EVT_BUTTON(BUTTONC_ID, MainFrame::OnButtonCClicked)
	EVT_BUTTON(BUTTONBACKSPACE_ID, MainFrame::OnButtonBackSpaceClicked)
	EVT_BUTTON(BUTTONRECIPRICAL_ID, MainFrame::OnButtonRecipricalClicked)
	EVT_BUTTON(BUTTONSQUARE_ID, MainFrame::OnButtonSquareClicked)
	EVT_BUTTON(BUTTONSQRT_ID, MainFrame::OnButtonSQRTClicked)
	EVT_BUTTON(BUTTONDIVISION_ID, MainFrame::OnButtonDivisionClicked)
	EVT_BUTTON(BUTTONMUL_ID, MainFrame::OnButtonMulClicked)
	EVT_BUTTON(BUTTONSUB_ID, MainFrame::OnButtonSubClicked)
	EVT_BUTTON(BUTTONADD_ID, MainFrame::OnButtonAddClicked)
	EVT_BUTTON(BUTTONEQUALS_ID, MainFrame::OnButtonEqualsClicked)
	EVT_BUTTON(BUTTONNEGATE_ID, MainFrame::OnButtonNegateClicked)
	EVT_BUTTON(BUTTONDECIMAL_ID, MainFrame::OnButtonDecimalClicked)

wxEND_EVENT_TABLE()

// Create GUI, call functions to create displays and controls
MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title) {

	SetupControls();
	SetupSizers();
	CreateStatusBar();

	}

// Create Fonts, Panel, and initial Text
void MainFrame::SetupControls() {

	// Create fonts
	wxFont headlineFont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont mainFont(wxFontInfo(wxSize(0, 24)).Bold());

	// Creates panel, headline text, and initial calculator display test
	panel = new wxPanel(this);
	panel->SetFont(mainFont);

	headlineText = new wxStaticText(panel, wxID_ANY, "Calculator");
	headlineText->SetFont(headlineFont);

	calculatorDisplayedText = wxString::Format("0"); 
	calculatorDisplay = new wxStaticText(panel, wxID_ANY, calculatorDisplayedText, wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
	calculatorDisplay->SetBackgroundColour(*wxLIGHT_GREY);
	calculatorDisplay->SetFont(headlineFont);

}

// Creates all sizers, assigns text and buttons
void MainFrame::SetupSizers() {

	// Create calculator headline text
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(headlineText, wxSizerFlags().CenterHorizontal());

	// Create calculator display
	wxBoxSizer* calculatorDisplaySizer = new wxBoxSizer(wxHORIZONTAL);
	calculatorDisplaySizer->Add(calculatorDisplay, wxSizerFlags().Proportion(1));
	mainSizer->Add(calculatorDisplaySizer, wxSizerFlags().Expand());

	// Create button grid 
	wxGridSizer* gridSizer = new wxGridSizer(6, 4, wxSize(0, 0));
	wxSizerFlags buttonFlags = wxSizerFlags().Expand();
	AddNumpadButtons();
	for (wxButton* button : buttons) {
		gridSizer->Add(button, buttonFlags);
	}
	mainSizer->Add(gridSizer, wxSizerFlags().Expand().Proportion(1));

	// Assigns main sizer to the panel, adjusts size to fit window size
	panel->SetSizer(mainSizer);
	mainSizer->SetSizeHints(this);
}

// Called once to create the num pad buttons and assign to a vector
void MainFrame::AddNumpadButtons() {
	
	// Start first 2 rows

	wxButton* buttonPercent = new wxButton(panel, BUTTONPERCENT_ID, "%", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(buttonPercent);

	wxButton* buttonCE = new wxButton(panel, BUTTONCE_ID, "CE", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(buttonCE);

	wxButton* buttonC = new wxButton(panel, BUTTONC_ID, "C", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(buttonC);

	wxButton* buttonBackSpace = new wxButton(panel, BUTTONBACKSPACE_ID, "<-", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(buttonBackSpace);

	wxButton* buttonReciprical = new wxButton(panel, BUTTONRECIPRICAL_ID, "1/x", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(buttonReciprical);

	wxButton* buttonSquare = new wxButton(panel, BUTTONSQUARE_ID, "x^2", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(buttonSquare);

	wxButton* buttonSQRT = new wxButton(panel, BUTTONSQRT_ID, "sqrt(x)", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(buttonSQRT);

	wxButton* buttonDivision = new wxButton(panel, BUTTONDIVISION_ID, "/", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(buttonDivision);



	// Start Numpad Buttons

	wxButton* button7 = new wxButton(panel, BUTTON7_ID, "7", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(button7);

	wxButton* button8 = new wxButton(panel, BUTTON8_ID, "8", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(button8);

	wxButton* button9 = new wxButton(panel, BUTTON9_ID, "9", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(button9);

	wxButton* buttonMul = new wxButton(panel, BUTTONMUL_ID, "x", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(buttonMul);


	wxButton* button4 = new wxButton(panel, BUTTON4_ID, "4", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(button4);

	wxButton* button5 = new wxButton(panel, BUTTON5_ID, "5", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(button5);

	wxButton* button6 = new wxButton(panel, BUTTON6_ID, "6", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(button6);

	wxButton* buttonSub = new wxButton(panel, BUTTONSUB_ID, "-", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(buttonSub);


	wxButton* button1 = new wxButton(panel, BUTTON1_ID, "1", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(button1);

	wxButton* button2 = new wxButton(panel, BUTTON2_ID, "2", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(button2);

	wxButton* button3 = new wxButton(panel, BUTTON3_ID, "3", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(button3);

	wxButton* buttonAdd = new wxButton(panel, BUTTONADD_ID, "+", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(buttonAdd);


	wxButton* buttonNegate = new wxButton(panel, BUTTONNEGATE_ID, "+/-", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(buttonNegate);

	wxButton* button0 = new wxButton(panel, BUTTON0_ID, "0", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(button0);

	wxButton* buttonDecimal = new wxButton(panel, BUTTONDECIMAL_ID, ".", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(buttonDecimal);

	wxButton* buttonEquals = new wxButton(panel, BUTTONEQUALS_ID, "=", wxDefaultPosition, wxDefaultSize);
	buttons.push_back(buttonEquals);

}

// Get input of a number, concatenate it to the current number, return as int
void MainFrame::ConcatenateNumber(std::string inputString) {

	IsLastInputAnOperator = false;

	// init empty string, concatenate input string onto the existing number
	// Then convert it to a double, call UpdateDisplay method
	std::string result = "";
	if (IsJustCalculated && inputString != ".") {
		currentNumStr = "";
		result += currentNumStr;
		result += inputString;
		currentNumStr = result;
		currentNum = stod(result);
		IsJustCalculated = false;
	}
	// If the first value entered is a decimal
	else if (IsJustCalculated && inputString == ".") {
		currentNumStr = "";
		result += currentNumStr;
		result += "0.";
		currentNumStr = result;
		currentNum = stod(result);
		IsJustCalculated = false;
	}
	// If the value has not just been calculated (not the first input value)
	else if (!IsJustCalculated) {

		result += currentNumStr;

		// if the input string is a '.' and there is no other decimal in the current number
		if (inputString == "." && currentNumStr.find('.') == std::string::npos) {
			result += inputString;
		}
		// if input string is not a decimal or the current number has no decimals
		else if (inputString != "." || currentNumStr.find('.') == std::string::npos) {
			result += inputString;
		}

		currentNumStr = result;
		currentNum = stod(result);

	}
	
	UpdateDisplay();
}

// This will update the calculator display to represent what the current number is.
void MainFrame::UpdateDisplay() {

	// Delete the old displayed text
	if (calculatorDisplay) {
		calculatorDisplay->Hide();
		panel->GetSizer()->Detach(calculatorDisplay);
		delete calculatorDisplay;
	}
	
	// handle the different display names
	if (currentNumStr == "") {
		calculatorDisplayedText = "0";
	}
	// handle divide by zero
	else if (IsDivByZero) {
		calculatorDisplayedText = "DIVIDE BY 0 ERROR";
		Clear();
	}
	// handle overflow error
	else if (std::isinf(currentNum)) {
		calculatorDisplayedText = "OVERFLOW ERROR";
	}
	else {
		calculatorDisplayedText = currentNumStr;
	}

	// Create new display text of currentNum w/color and font
	calculatorDisplay = new wxStaticText(panel, wxID_ANY, calculatorDisplayedText, wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
	calculatorDisplay->SetBackgroundColour(*wxLIGHT_GREY);
	calculatorDisplay->SetFont(wxFont(wxFontInfo(wxSize(0, 36)).Bold()));

	// Create new sizer and insert text.
	wxBoxSizer* mainSizer = dynamic_cast<wxBoxSizer*>(panel->GetSizer());
	if (mainSizer) {
		wxBoxSizer* calculatorDisplaySizer = new wxBoxSizer(wxHORIZONTAL);
		calculatorDisplaySizer->Add(calculatorDisplay, wxSizerFlags().Proportion(1).Expand());
		mainSizer->Insert(1, calculatorDisplaySizer, 0, wxEXPAND, 0);  
	}

	// Recalculate the layout to adjust the window size based on the new display
	panel->Layout();

}

// Handles all calculation inputs including instant operations (like sqrt) and delayed operations (like +)
void MainFrame::Calculate() {

	IsJustCalculated = true;

	// Handle all operations
	if (operationStr == "+") {
		currentNum += oldNum;
		if (IsRepeatingOperations) {
			oldNum = currentNum;
		}
	}
	else if (operationStr == "-") {
		currentNum = oldNum - currentNum;
		if (IsRepeatingOperations) {
			oldNum = currentNum;
		}
	}
	else if (operationStr == "x") {
		currentNum *= oldNum;
		if (IsRepeatingOperations) {
			oldNum = currentNum;
		}
	}
	else if (operationStr == "/") {
		if (currentNum != 0) {
			currentNum = oldNum / currentNum;
		}
		else {
			IsDivByZero = true;
			UpdateDisplay();
			return;
		}
		if (IsRepeatingOperations) {
			oldNum = currentNum;
		}
	}
	else if (operationStr == "sqrt") {
		currentNum = sqrt(oldNum);
	}
	else if (operationStr == "sq") {
		currentNum = pow(oldNum, 2);
	}
	else if (operationStr == "1/x") {
		currentNum = 1/oldNum;
	}
	else if (operationStr == "percent") {
		currentNum = oldNum*100;
	}
	else if (operationStr == "+/-") {
		currentNum = -oldNum;
	}

	// Save current number string to class member variable and update display
	currentNumStr = std::to_string(currentNum);
	operationStr = "";
	UpdateDisplay();
	if (EqualsPressed) {
		IsRepeatingOperations = false;
	}
}

void MainFrame::CalculateRepeatingOperations(std::string newOperation) {
	
	// If user divided by zero before doing next operation
	if (currentNum == 0 && operationStr == "/") {
		IsDivByZero = true;
		UpdateDisplay();
		return;
	}
	
	if (newOperation == "sqrt") {
		currentNum = sqrt(currentNum);
	}
	else if (newOperation == "sq") {
		currentNum = pow(currentNum, 2);
	}
	else if (newOperation == "1/x") {
		if (currentNum != 0) { // calculate normal reciprical
			currentNum = 1 / currentNum;
		}
		else { // throw error if user tries to take the reciprical of 0
			IsDivByZero = true;
			UpdateDisplay();
			return;
		}
	}
	else if (newOperation == "percent") {
		currentNum = currentNum * 100;
	}
	else if (newOperation == "+/-") {
		currentNum = -currentNum;
	}
	currentNumStr = std::to_string(currentNum);
	UpdateDisplay();
}

void MainFrame::Clear() {
	currentNumStr = "";
	currentNum = 0;
	oldNum = 0;
	IsDivByZero = false;
	IsJustCalculated = true;
	IsRepeatingOperations = false;
	IsLastInputAnOperator = false;
}

/*
The many following methods are executed on events (when a button is pressed)
*/
void MainFrame::OnButton1Clicked(wxCommandEvent& evt) {
	ConcatenateNumber("1");
}

void MainFrame::OnButton2Clicked(wxCommandEvent& evt) {
	ConcatenateNumber("2");
}

void MainFrame::OnButton3Clicked(wxCommandEvent& evt) {
	ConcatenateNumber("3");
}

void MainFrame::OnButton4Clicked(wxCommandEvent& evt) {
	ConcatenateNumber("4");
}

void MainFrame::OnButton5Clicked(wxCommandEvent& evt) {
	ConcatenateNumber("5");
}

void MainFrame::OnButton6Clicked(wxCommandEvent& evt) {
	ConcatenateNumber("6");
}

void MainFrame::OnButton7Clicked(wxCommandEvent& evt) {
	ConcatenateNumber("7");
}

void MainFrame::OnButton8Clicked(wxCommandEvent& evt) {
	ConcatenateNumber("8");
}

void MainFrame::OnButton9Clicked(wxCommandEvent& evt) {
	ConcatenateNumber("9");
}

void MainFrame::OnButton0Clicked(wxCommandEvent& evt) {
	ConcatenateNumber("0");

}

void MainFrame::OnButtonPercentClicked(wxCommandEvent& evt) {

	// Ensure that the user cannot enter multiple operators in succession
	if (!IsLastInputAnOperator) {

		// check if user is taking reciprical after a previous operation
		if (!IsRepeatingOperations) {
			oldNum = currentNum;
			currentNumStr = "";
			operationStr = "percent";
			Calculate();
		}
		else { // repeating operations
			CalculateRepeatingOperations("percent");
		}
	}

}

void MainFrame::OnButtonCEClicked(wxCommandEvent& evt) {
	Clear();
	UpdateDisplay();
}

void MainFrame::OnButtonCClicked(wxCommandEvent& evt) {
	Clear();
	UpdateDisplay();
}

void MainFrame::OnButtonBackSpaceClicked(wxCommandEvent& evt) {

	// Remove last entered character so long as the string has more than 0 characters
	if (currentNumStr.length() > 0 && !IsJustCalculated) {
		currentNumStr.pop_back();
		UpdateDisplay();
	}
}

void MainFrame::OnButtonRecipricalClicked(wxCommandEvent& evt) {

	// Ensure that the user cannot enter multiple operators in succession
	if (!IsLastInputAnOperator) {

		// check if user is taking reciprical after a previous operation
		if (!IsRepeatingOperations) {
			
			// Ensure that user cannot take reciprical of 0
			if (currentNum != 0) {
				oldNum = currentNum;
				currentNumStr = "";
				operationStr = "1/x";
				Calculate();
			}
			else { // if user is taking reciprical of 0 throw a div by 0 error
				IsDivByZero = true;
				UpdateDisplay();
				return;
			}
		}
		else { // repeating operations
			CalculateRepeatingOperations("1/x");		
		}
	}

}

void MainFrame::OnButtonSquareClicked(wxCommandEvent& evt) {
	// Ensure that the user cannot enter multiple operators in succession
	if (!IsLastInputAnOperator) {

		// check if user is squaring a number after a previous operation
		if (!IsRepeatingOperations) {
			oldNum = currentNum;
			currentNumStr = "";
			operationStr = "sq";
			Calculate();
		}
		else { // repeating operations
			CalculateRepeatingOperations("sq");
		}

	}
}

void MainFrame::OnButtonSQRTClicked(wxCommandEvent& evt) {

	// Ensure that the user cannot enter multiple operators in succession
	if (!IsLastInputAnOperator) {

		// check if user is squaring a number after a previous operation
		if (!IsRepeatingOperations) {
			oldNum = currentNum;
			currentNumStr = "";
			operationStr = "sqrt";
			Calculate();
		}
		else { // repeating operations
			CalculateRepeatingOperations("sqrt");
		}
	}
}

void MainFrame::OnButtonDivisionClicked(wxCommandEvent& evt) {

	// Ensure that the user cannot enter multiple operators in succession
	if (!IsLastInputAnOperator) {
		// Check if an operation has been used multiple times in a row without using
		// the equals operator. For example, "5+3+2=" this should produce 10.  
		if (!IsRepeatingOperations) {
			oldNum = currentNum;
			UpdateDisplay();
		}
		else { // If operation is repeating
			// if number entered before operation is not 0, then calculate it normally
			if (currentNum != 0) {
				Calculate();
			}
			else { // if number entered before operation is 0, then give a div by 0 error
				IsDivByZero = true;
				UpdateDisplay();
				return;
			}

		}

		operationStr = "/";
		currentNumStr = "";
		IsJustCalculated = true;
		IsRepeatingOperations = true;
		IsLastInputAnOperator = true;
	}	
}

void MainFrame::OnButtonMulClicked(wxCommandEvent& evt) {
	
	// Ensure that the user cannot enter multiple operators in succession
	if (!IsLastInputAnOperator) {
		if (!IsRepeatingOperations) {
			oldNum = currentNum;
		}
		else {
			if (currentNum != 0) { // multiply standard numbers
				Calculate();
			}
			else if (operationStr == "/") { // if previous operaiton was division
				IsDivByZero = true;
				UpdateDisplay();
				return;
			}
			else { // multiply by 0
				Calculate();
			}

		}

		operationStr = "x";
		currentNumStr = "";
		IsJustCalculated = true;
		IsRepeatingOperations = true;
		IsLastInputAnOperator = true;
	}	
}

void MainFrame::OnButtonSubClicked(wxCommandEvent& evt) {
	
	// Ensure that the user cannot enter multiple operators in succession
	if (!IsLastInputAnOperator) {
		if (!IsRepeatingOperations) {
			oldNum = currentNum;
		}
		else {
			if (currentNum != 0) { // handles standard number inputs
				Calculate();
			}
			else if (operationStr == "/") { // if previous operation was division & currentNum=0
				IsDivByZero = true;
				wxLogStatus("div 0");
				UpdateDisplay();
				return;
			}
			else { // subtract by 0
				Calculate();
			}
		}

		operationStr = "-";
		currentNumStr = "";
		IsJustCalculated = true;
		IsRepeatingOperations = true;
		IsLastInputAnOperator = true;
	}
}

void MainFrame::OnButtonAddClicked(wxCommandEvent& evt) {
	// Ensure that the user cannot enter multiple operators in succession
	if (!IsLastInputAnOperator) {
		if (!IsRepeatingOperations) {
			oldNum = currentNum;
		}
		else {
			if (currentNum != 0) { // handles standard number inputs
				Calculate();
			}
			else if (operationStr == "/") { // if previous operation was division & currentNum=0
				IsDivByZero = true;
				wxLogStatus("div 0");
				UpdateDisplay();
				return;
			}
			else { // add 0
				Calculate();
			}
		}

		operationStr = "+";
		currentNumStr = "";
		IsJustCalculated = true;
		IsRepeatingOperations = true;
		IsLastInputAnOperator = true;
	}
}

void MainFrame::OnButtonEqualsClicked(wxCommandEvent& evt) {
	EqualsPressed = true;
	Calculate();
}

void MainFrame::OnButtonNegateClicked(wxCommandEvent& evt) {
	// Ensure that the user cannot enter multiple operators in succession
	if (!IsLastInputAnOperator) {

		// check if user is squaring a number after a previous operation
		if (!IsRepeatingOperations) {
			oldNum = currentNum;
			currentNumStr = "";
			operationStr = "+/-";
			Calculate();
		}
		else { // repeating operations
			CalculateRepeatingOperations("+/-");
		}
	}
}

void MainFrame::OnButtonDecimalClicked(wxCommandEvent& evt) {
	ConcatenateNumber(".");
}
