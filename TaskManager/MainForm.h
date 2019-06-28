#pragma once
#include <vector>
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include "pdh.h"
#include "AboutForm.h"

#pragma comment(lib, "pdh.lib")
#pragma comment(lib,"User32.lib")

namespace TaskManager {

	using namespace System;
	using namespace System::Diagnostics;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ MainForm
	/// </summary>

	FILETIME idle, prev_idle;
	FILETIME kernel, prev_kernel;
	FILETIME user, prev_user;
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			GetProcessList();
			Initialize();

			//
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ôàéëToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  íîâåÇàäà÷àToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  âèõ³äToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ä³ÿToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  çíÿòèÇàäà÷óToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  íîâàÇàäà÷àToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  äîâ³äêàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ïğîÏğîãğàìóToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ïğîÀâòîğàToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^  dataGridView1;





	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  CPUchart;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  RAMchart;
	private: System::Windows::Forms::Label^  label4;
	private: AboutForm^ aboutForm;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Memory;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Threads;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Priority;





















	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ôàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->íîâåÇàäà÷àToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->âèõ³äToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ä³ÿToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->çíÿòèÇàäà÷óToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->íîâàÇàäà÷àToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->äîâ³äêàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïğîÏğîãğàìóToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïğîÀâòîğàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->CPUchart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->RAMchart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Memory = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Threads = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Priority = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CPUchart))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RAMchart))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ôàéëToolStripMenuItem,
					this->ä³ÿToolStripMenuItem, this->äîâ³äêàToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(792, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ôàéëToolStripMenuItem
			// 
			this->ôàéëToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->íîâåÇàäà÷àToolStripMenuItem,
					this->toolStripMenuItem1, this->âèõ³äToolStripMenuItem
			});
			this->ôàéëToolStripMenuItem->Name = L"ôàéëToolStripMenuItem";
			this->ôàéëToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->ôàéëToolStripMenuItem->Text = L"Ôàéë";
			// 
			// íîâåÇàäà÷àToolStripMenuItem
			// 
			this->íîâåÇàäà÷àToolStripMenuItem->Name = L"íîâåÇàäà÷àToolStripMenuItem";
			this->íîâåÇàäà÷àToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->íîâåÇàäà÷àToolStripMenuItem->Text = L"Íîâå çàäà÷à";
			this->íîâåÇàäà÷àToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::íîâåÇàäà÷àToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(138, 6);
			// 
			// âèõ³äToolStripMenuItem
			// 
			this->âèõ³äToolStripMenuItem->Name = L"âèõ³äToolStripMenuItem";
			this->âèõ³äToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->âèõ³äToolStripMenuItem->Text = L"Âèõ³ä";
			this->âèõ³äToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::âèõ³äToolStripMenuItem_Click);
			// 
			// ä³ÿToolStripMenuItem
			// 
			this->ä³ÿToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->çíÿòèÇàäà÷óToolStripMenuItem,
					this->íîâàÇàäà÷àToolStripMenuItem
			});
			this->ä³ÿToolStripMenuItem->Name = L"ä³ÿToolStripMenuItem";
			this->ä³ÿToolStripMenuItem->Size = System::Drawing::Size(36, 20);
			this->ä³ÿToolStripMenuItem->Text = L"Ä³ÿ";
			// 
			// çíÿòèÇàäà÷óToolStripMenuItem
			// 
			this->çíÿòèÇàäà÷óToolStripMenuItem->Name = L"çíÿòèÇàäà÷óToolStripMenuItem";
			this->çíÿòèÇàäà÷óToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->çíÿòèÇàäà÷óToolStripMenuItem->Text = L"Çíÿòè çàäà÷ó";
			this->çíÿòèÇàäà÷óToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::çíÿòèÇàäà÷óToolStripMenuItem_Click);
			// 
			// íîâàÇàäà÷àToolStripMenuItem
			// 
			this->íîâàÇàäà÷àToolStripMenuItem->Name = L"íîâàÇàäà÷àToolStripMenuItem";
			this->íîâàÇàäà÷àToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->íîâàÇàäà÷àToolStripMenuItem->Text = L"Íîâà çàäà÷à";
			this->íîâàÇàäà÷àToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::íîâàÇàäà÷àToolStripMenuItem_Click);
			// 
			// äîâ³äêàToolStripMenuItem
			// 
			this->äîâ³äêàToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ïğîÏğîãğàìóToolStripMenuItem,
					this->ïğîÀâòîğàToolStripMenuItem
			});
			this->äîâ³äêàToolStripMenuItem->Name = L"äîâ³äêàToolStripMenuItem";
			this->äîâ³äêàToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->äîâ³äêàToolStripMenuItem->Text = L"Äîâ³äêà";
			// 
			// ïğîÏğîãğàìóToolStripMenuItem
			// 
			this->ïğîÏğîãğàìóToolStripMenuItem->Name = L"ïğîÏğîãğàìóToolStripMenuItem";
			this->ïğîÏğîãğàìóToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->ïğîÏğîãğàìóToolStripMenuItem->Text = L"Ïğî ïğîãğàìó";
			this->ïğîÏğîãğàìóToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ïğîÏğîãğàìóToolStripMenuItem_Click);
			// 
			// ïğîÀâòîğàToolStripMenuItem
			// 
			this->ïğîÀâòîğàToolStripMenuItem->Name = L"ïğîÀâòîğàToolStripMenuItem";
			this->ïğîÀâòîğàToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->ïğîÀâòîğàToolStripMenuItem->Text = L"Ïğî àâòîğà";
			this->ïğîÀâòîğàToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ïğîÀâòîğàToolStripMenuItem_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Name, this->ID,
					this->Memory, this->Threads, this->Priority
			});
			this->dataGridView1->Location = System::Drawing::Point(0, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(787, 354);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->RowHeaderMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MainForm::dataGridView1_RowHeaderMouseDoubleClick);
			this->dataGridView1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::dataGridView1_Paint);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(619, 363);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(160, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Çàâåğøèòè ïğîöåñ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(478, 363);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(135, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Îíîâèòè ñïèñîê";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 368);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Ïàì\'ÿòü:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(195, 368);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"ÖÏ:";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(0, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(795, 420);
			this->tabControl1->TabIndex = 6;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(787, 394);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Òàáëèöÿ ïğîöåñ³â";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label3);
			this->tabPage2->Controls->Add(this->CPUchart);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(787, 394);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Ãğàô³ê ÖÏ";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(677, 36);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 17);
			this->label3->TabIndex = 1;
			this->label3->Text = L"label3";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CPUchart
			// 
			this->CPUchart->AllowDrop = true;
			this->CPUchart->BorderlineColor = System::Drawing::Color::Black;
			chartArea1->AxisY->Maximum = 100;
			chartArea1->Name = L"ChartArea1";
			this->CPUchart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->CPUchart->Legends->Add(legend1);
			this->CPUchart->Location = System::Drawing::Point(0, 0);
			this->CPUchart->Name = L"CPUchart";
			series1->BorderWidth = 5;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"Íàâàíòàæåííÿ ÖÏ";
			this->CPUchart->Series->Add(series1);
			this->CPUchart->Size = System::Drawing::Size(788, 394);
			this->CPUchart->TabIndex = 0;
			this->CPUchart->Text = L"chart1";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label4);
			this->tabPage3->Controls->Add(this->RAMchart);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(787, 394);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Ãğàô³ê ïàì\'ÿò³";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(641, 39);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 17);
			this->label4->TabIndex = 1;
			this->label4->Text = L"label4";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// RAMchart
			// 
			chartArea2->Name = L"ChartArea1";
			this->RAMchart->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->RAMchart->Legends->Add(legend2);
			this->RAMchart->Location = System::Drawing::Point(0, 0);
			this->RAMchart->Name = L"RAMchart";
			series2->BorderWidth = 5;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->MarkerColor = System::Drawing::Color::White;
			series2->Name = L"Âèêîğèñòàííÿ ïàì\'ÿò³";
			this->RAMchart->Series->Add(series2);
			this->RAMchart->Size = System::Drawing::Size(791, 394);
			this->RAMchart->TabIndex = 0;
			this->RAMchart->Text = L"chart1";
			// 
			// Name
			// 
			this->Name->HeaderText = L"Íàçâà";
			this->Name->Name = L"Name";
			this->Name->ReadOnly = true;
			this->Name->Width = 300;
			// 
			// ID
			// 
			this->ID->HeaderText = L"²Ä ïğîöåñó";
			this->ID->Name = L"ID";
			this->ID->ReadOnly = true;
			// 
			// Memory
			// 
			this->Memory->HeaderText = L"Ïàì\'ÿòü";
			this->Memory->Name = L"Memory";
			this->Memory->ReadOnly = true;
			// 
			// Threads
			// 
			this->Threads->HeaderText = L"Ê³ëüê³ñòü ïîòîê³â";
			this->Threads->Name = L"Threads";
			this->Threads->ReadOnly = true;
			// 
			// Priority
			// 
			this->Priority->HeaderText = L"Ïğèîğèòåò";
			this->Priority->Name = L"Priority";
			this->Priority->ReadOnly = true;
			this->Priority->Width = 130;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(792, 448);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
//			this->Name = L"MainForm";
			this->Text = L"Task Manager";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CPUchart))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RAMchart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//Fields:
		int CPUUsage;
		double RAMUsage;
		double RAMTotal;
	//Methods:

	void Initialize() {
		GetRAMUsage();
		GetCpuUsage();
		RAMchart->ChartAreas[0]->AxisY->Maximum = RAMTotal + 1;
	}

	BOOL GetProcessList()
	{
		HANDLE hProcessSnap;
		HANDLE hProcess;
		PROCESSENTRY32 pe32;
		DWORD dwPriorityClass;
		dataGridView1->Rows->Clear();

		hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (hProcessSnap == INVALID_HANDLE_VALUE)
		{
			return(FALSE);
		}

		pe32.dwSize = sizeof(PROCESSENTRY32);

		if (!Process32First(hProcessSnap, &pe32))
		{
			CloseHandle(hProcessSnap);
			return(FALSE);
		}

		do
		{
			dwPriorityClass = 0;
			hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
			if (hProcess == NULL) {}
			else
			{
				dwPriorityClass = GetPriorityClass(hProcess);
				if (!dwPriorityClass) {}
				CloseHandle(hProcess);
			}

			dataGridView1->Rows->Add(
				gcnew String(pe32.szExeFile),
				pe32.th32ProcessID,
				"",
				pe32.cntThreads,
				pe32.pcPriClassBase);

		} while (Process32Next(hProcessSnap, &pe32));

		CloseHandle(hProcessSnap);
		return(TRUE);
	}

	void PrintMemoryInfo(DWORD processID, int i)
	{
		HANDLE hProcess;
		PROCESS_MEMORY_COUNTERS pmc;

		hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
			PROCESS_VM_READ,
			FALSE, processID);
		if (NULL == hProcess)
			return;

		if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
		{
			dataGridView1->Rows[i]->Cells[2]->Value = pmc.WorkingSetSize / 1024;
		}

		CloseHandle(hProcess);
	}

	ULONGLONG ft2ull(FILETIME &ft) {
		ULARGE_INTEGER ul;
		ul.HighPart = ft.dwHighDateTime;
		ul.LowPart = ft.dwLowDateTime;
		return ul.QuadPart;
	}

	void GetCpuUsage() {
		GetSystemTimes(&idle, &kernel, &user);
		ULONGLONG sys = (ft2ull(user) - ft2ull(prev_user)) +
			(ft2ull(kernel) - ft2ull(prev_kernel));
		int cpu = int((sys - ft2ull(idle) + ft2ull(prev_idle)) * 100.0 / sys);
		prev_idle = idle;
		prev_kernel = kernel;
		prev_user = user;
		CPUUsage = cpu;
	}

	void GetRAMUsage()
	{
		MEMORYSTATUSEX memInfo;
		memInfo.dwLength = sizeof(MEMORYSTATUSEX);
		GlobalMemoryStatusEx(&memInfo);
		DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
		DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;
		RAMUsage = (round((double)physMemUsed / (1024 * 1024 * 1024) * 10) / 10);
		RAMTotal = (round((double)totalPhysMem / (1024 * 1024 * 1024) * 10) / 10);
	}


	void KillProcess(int row) 
	{
		HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, Convert::ToInt32(dataGridView1->Rows[row]->Cells[1]->Value));
		TerminateProcess(hProcess, 0);
		CloseHandle(hProcess);
		GetProcessList();
	}

	//Events:

	private: System::Void dataGridView1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
	{

	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		for (int i = 0; i < dataGridView1->Rows->Count; i++) {
			PrintMemoryInfo(Convert::ToInt32(dataGridView1->Rows[i]->Cells[1]->Value), i);
		}

		GetCpuUsage();
		GetRAMUsage();
		if (CPUchart->Series[0]->Points->Count >= 60) {
			CPUchart->Series[0]->Points[59]->SetValueY(CPUUsage);
			RAMchart->Series[0]->Points[59]->SetValueY(RAMUsage);
			for (int i = 0; i < 59; i++) {
				CPUchart->Series[0]->Points[i] = (CPUchart->Series[0]->Points[i + 1])->Clone();
				RAMchart->Series[0]->Points[i] = (RAMchart->Series[0]->Points[i + 1])->Clone();
			}
		}
		else {
			CPUchart->Series[0]->Points->AddY(CPUUsage);
			RAMchart->Series[0]->Points->AddY(RAMUsage);
		}
		label2->Text = "ÖÏ: " + CPUUsage + " %";
		label1->Text = "Ïàì'ÿòü : " + RAMUsage + " / " + RAMTotal + " ÃÁ";
		label3->Text = CPUUsage + " %";
		label4->Text = RAMUsage + " / " + RAMTotal + " ÃÁ";


	}

	void NewProcess() 
	{
		keybd_event(VK_LWIN, 0, 0, 0);
		keybd_event(0x52, 0, 0, 0);
		keybd_event(0x52, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(VK_LWIN, 0, KEYEVENTF_KEYUP, 0);
	}

	private: System::Void íîâåÇàäà÷àToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		NewProcess();
	}

	private: System::Void dataGridView1_RowHeaderMouseDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) 
	{
		KillProcess(e->RowIndex);
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		KillProcess(dataGridView1->CurrentRow->Index);
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		GetProcessList();
	}

	private: System::Void ïğîÏğîãğàìóToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		aboutForm = gcnew AboutForm();
	}

	private: System::Void ïğîÀâòîğàToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		System::Windows::Forms::MessageBox::Show("Âèêîíàâ ñòóäåíò ãğóïè 1Ï²-18ìñ: Ìàçóğ Îëåã", "Ïğî àâòîğà");
	}

	private: System::Void âèõ³äToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Close();
	}

	private: System::Void íîâàÇàäà÷àToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		NewProcess();
	}

	private: System::Void çíÿòèÇàäà÷óToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		KillProcess(dataGridView1->CurrentRow->Index);
	}
};
}