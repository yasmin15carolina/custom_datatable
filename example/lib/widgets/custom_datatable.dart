import 'package:flutter/material.dart';

// ignore: must_be_immutable
class CustomDataTable extends StatefulWidget {
  final Color headerColor;
  final Color rowColor1;
  final Color rowColor2;
  DataTable dataTable;
  CustomDataTable({@required this.dataTable,this.headerColor:Colors.indigoAccent,this.rowColor1:const Color(0xFFE0E0E0),this.rowColor2:Colors.white,});
  @override
  _CustomDataTableState createState() => _CustomDataTableState();
}

class _CustomDataTableState extends State<CustomDataTable> {
  BoxDecoration decorationHeader;
  BoxDecoration decorationRow1;
  BoxDecoration decorationRow2;

  @override
  void initState(){
    decorationHeader=BoxDecoration(
        color: widget.headerColor,
        borderRadius: BorderRadius.vertical(top:Radius.circular(5),),
        border: Border.all(width:1,color:Colors.black)
    );
    decorationRow1= BoxDecoration(
        color: widget.rowColor1,
        border: Border.all(width:1,color:Colors.black)
    );
    decorationRow2 = BoxDecoration(
        color: widget.rowColor2,
        border: Border.all(width:1,color:Colors.black)
    );
    super.initState();
  }
  Decoration decorationColumn = BoxDecoration(
      border: Border(right:BorderSide(width:1,color:Colors.black))
  );
  @override
  Widget build(BuildContext context) {
    return Stack(
        children:[
          Positioned.fill(
              child:
              Column(
                children:
                widget.dataTable.rows.map(
                        (e) {
                      if(widget.dataTable.rows.indexOf(e)==0){
                        return Column(
                            children:[
                              Container(decoration: decorationHeader,height: widget.dataTable.headingRowHeight,),
                              Container(decoration: decorationRow1,height: widget.dataTable.dataRowHeight,)
                            ]
                        );
                      }
                      else{
                        if(widget.dataTable.rows.indexOf(e)%2>0)
                          return Container(decoration: decorationRow2,height: widget.dataTable.dataRowHeight,);
                        else return Container(decoration: decorationRow1,height: widget.dataTable.dataRowHeight,);
                      }
                    }
                ).toList(),
              )
          ),
          widget.dataTable,
        ]);
  }
}