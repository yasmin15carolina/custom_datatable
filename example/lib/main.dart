import 'package:example/widgets/custom_datatable.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Custom Datatable example',
      theme: ThemeData(
        primarySwatch: Colors.blue,
        visualDensity: VisualDensity.adaptivePlatformDensity,
      ),
      debugShowCheckedModeBanner: false,
      home: MyHomePage(title: 'Custom Datatable example'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  MyHomePage({Key key, this.title}) : super(key: key);

  final String title;

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {

  TextStyle headerTextStyle =TextStyle(color:Colors.white,fontSize:20);
  @override
  Widget build(BuildContext context) {
    
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body: 
          Center(
            child: 
              CustomDataTable(
                dataTable: DataTable(
                  horizontalMargin: 24,
                  columnSpacing: 24,
                   columns: [DataColumn(label: Text("Name",style: headerTextStyle,),),DataColumn(label: Text("Email",style: headerTextStyle,),),DataColumn(label: Text("Adress",style: headerTextStyle,),),], 
                  rows: [
                    DataRow(cells: [DataCell(Text("Brandon")),DataCell(Text("brandon@gmail.com")),DataCell(Text("4982  Mutton Town Road"))]),
                    DataRow(cells: [DataCell(Text("Jane")),DataCell(Text("jane@gmail.com")),DataCell(Text("1800  Fort Street")),]),
                    DataRow(cells: [DataCell(Text("John"),),DataCell(Text("john@gmail.com"),),DataCell(Text("1308  Berkley Street"),),]),
                  ]
                ),
                rowColor1:Colors.grey.shade300,
                headerColor: Colors.green,
              )
          )          

    );
  }
}

