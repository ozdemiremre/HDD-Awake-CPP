#pragma once
#include <fstream>
#include <cstring>
#include <windows.h>
#include <ctime>
#include <msclr\marshal_cppstd.h>
#include <shellapi.h>

using namespace std;

std::string SELECTEDPATH;
bool writeState = false;

FILE *cfPtr;		//File pointer





namespace HDDAwakeCPP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace System::IO;
	using namespace System::Security;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}

		void CreateLayers(){

			AccessControl::DirectorySecurity^ securityRules = gcnew AccessControl::DirectorySecurity();


			std::string pathLayers[5] =
			{
				SELECTEDPATH + "\\Layer1",
				SELECTEDPATH + "\\Layer1\\Layer2",
				SELECTEDPATH + "\\Layer1\\Layer2\\Layer3",
				SELECTEDPATH + "\\Layer1\\Layer2\\Layer3\\Layer4",
				SELECTEDPATH + "\\Layer1\\Layer2\\Layer3\\Layer4\\Layer5"
			};

			for(int i=0;i<5;++i){
				LPCSTR str_path = pathLayers[i].c_str();
				String^ path1;
				path1 = marshal_as<String^>( pathLayers[i] );

				securityRules->AddAccessRule(gcnew AccessControl::FileSystemAccessRule("Emre Ozdemir", AccessControl::FileSystemRights::FullControl, AccessControl::AccessControlType::Allow));

				IO::Directory::CreateDirectory( path1, securityRules );	
			}
		};

		void DeleteLayers(){

			std::string pathLayers[6] =
			{
				SELECTEDPATH + "\\Layer1",
				SELECTEDPATH + "\\Layer1\\Layer2",
				SELECTEDPATH + "\\Layer1\\Layer2\\Layer3",
				SELECTEDPATH + "\\Layer1\\Layer2\\Layer3\Layer4",
				SELECTEDPATH + "\\Layer1\\Layer2\\Layer3\\Layer4\\Layer5",
				SELECTEDPATH + "\\Layer1\\Layer2\\Layer3\\Layer4\\Layer5\\EmreHD.txt"
			};

			for(int i=5; i>=0; --i){
				LPCSTR str_path = pathLayers[i].c_str();     //delete target folder
				//				remove(str_path);
				//				RemoveDirectoryA(str_path);		
				//				DeleteFileA(str_path);

				String^ path1;
				path1 = marshal_as<String^>( pathLayers[i] );
				IO::File::Delete(path1);
			}
		};


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{


				delete components;
			}

			delete backgroundWorker1;
			DeleteLayers();
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  selectedDirLabel;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::Button^  write;
	private: System::Windows::Forms::NotifyIcon^  notifyIcon1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->selectedDirLabel = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->write = (gcnew System::Windows::Forms::Button());
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(229, 38);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Select Directory to Write In";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(13, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"-:";
			// 
			// selectedDirLabel
			// 
			this->selectedDirLabel->AutoSize = true;
			this->selectedDirLabel->Location = System::Drawing::Point(25, 53);
			this->selectedDirLabel->Name = L"selectedDirLabel";
			this->selectedDirLabel->Size = System::Drawing::Size(0, 13);
			this->selectedDirLabel->TabIndex = 2;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->DecimalPlaces = 1;
			this->numericUpDown1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 65536});
			this->numericUpDown1->Location = System::Drawing::Point(187, 75);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {15, 0, 0, 0});
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 65536});
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->ReadOnly = true;
			this->numericUpDown1->Size = System::Drawing::Size(44, 20);
			this->numericUpDown1->TabIndex = 4;
			this->numericUpDown1->TabStop = false;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 65536});
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 77);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(169, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Minute Difference Between Writes";
			// 
			// folderBrowserDialog1
			// 
			this->folderBrowserDialog1->RootFolder = System::Environment::SpecialFolder::MyComputer;
			// 
			// write
			// 
			this->write->Location = System::Drawing::Point(12, 101);
			this->write->Name = L"write";
			this->write->Size = System::Drawing::Size(229, 43);
			this->write->TabIndex = 6;
			this->write->Text = L"Write";
			this->write->UseVisualStyleBackColor = true;
			this->write->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"notifyIcon1.Icon")));
			this->notifyIcon1->Text = L"HDD Awake";
			this->notifyIcon1->Visible = true;
			this->notifyIcon1->DoubleClick += gcnew System::EventHandler(this, &Form1::notifyIcon1_DoubleClick);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(253, 156);
			this->Controls->Add(this->write);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->selectedDirLabel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"HDD Awake";
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 folderBrowserDialog1->ShowDialog();
				 SELECTEDPATH = marshal_as<string>( folderBrowserDialog1->SelectedPath->ToString() );
				 selectedDirLabel->Text = folderBrowserDialog1->SelectedPath;
				 //		 SELECTEDPATH.replace(SELECTEDPATH.find('\\'),0,"\\");  // Changed to D:\\...

			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {


				 if (writeState == false)
				 {
					 std::string path2 = SELECTEDPATH + "\\Layer1\\Layer2\\Layer3\\Layer4\\Layer5\\EmreHD.txt";
					 std::string path = SELECTEDPATH + "\\Layer1\\Layer2\\Layer3\\Layer4\\Layer5";
					 CreateLayers();
					 // fopen opens file. Exit program if unable to create file.
					 if((cfPtr = fopen( path2.c_str() ,"w" )) == NULL){	//change w -> a to preserve before contents.
						 MessageBox::Show ("File could not opened","Error", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);	//Display if file could not opened.
					 }

					 writeState = true;

					 backgroundWorker1->RunWorkerAsync();
					 write->ForeColor = Color::IndianRed;
					 write->BackColor = Color::Gold;
				 }


				 else if (writeState == true)
				 {
					 backgroundWorker1->CancelAsync();
					 write->ForeColor = write->DefaultForeColor;
					 write->BackColor = write->DefaultBackColor;

					 writeState = false;
				 }
			 }
	private: System::Void notifyIcon1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
				 Show();
				 WindowState = FormWindowState::Normal;
			 }
	private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e) {

				 if (WindowState == FormWindowState::Minimized)
					 Hide();

			 }
	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

				 std::string path2 = SELECTEDPATH + "\\Layer1\\Layer2\\Layer3\\Layer4\\Layer5\\EmreHD.txt";
				 std::string path = SELECTEDPATH + "\\Layer1\\Layer2\\Layer3\\Layer4\\Layer5";

				 double sleepMinute;
				 double sleepSec;
				 Decimal minute = numericUpDown1->Value;
				 sleepMinute = minute.ToDouble(minute);

				 while ( writeState == true){

					 if (backgroundWorker1->CancellationPending == true)
					 {
						 e->Cancel = true;
						 break; 
					 }

					 else
					 {
						 time_t t = time(0);   // get time now
						 struct tm * now = localtime( & t );
						 cfPtr = fopen( path2.c_str() ,"a" );
						 fprintf( cfPtr,"Created in :%d.%d.%d - %d:%d:%d \n",now->tm_mday, now->tm_mon + 1, now->tm_year + 1900, now->tm_hour, now->tm_min, now->tm_sec);
						 fflush(0); 
						 fclose(cfPtr);
						 fcloseall();
						 _sleep( sleepMinute * 60000.0 );
					 }
				 }
			 }
	};

}

/*TODO:
-Auto-Startup
-Delete directories after stopping App
-Give only HDD options in select directory dialog
-

*/
