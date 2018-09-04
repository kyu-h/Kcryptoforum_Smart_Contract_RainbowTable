<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Page Title</title>
    <script type=”text/javascript” src=”web3.min.js”></script>
    <script type=”text/javascript” src=”eth.js”></script>
    <script src="https://cdn.jsdelivr.net/gh/ethereum/web3.js/dist/web3.min.js"></script>
    <script src="http://code.jquery.com/jquery-1.10.2.js"></script> <!-- jquery 사용하고 싶을 경우  import -->
</head>
<style>
    table, th, td {
        border: 1px solid black;
    }
</style>
<body>
    <script>
        var cookie = document.cookie;
        var split_cookie = cookie.split('/');
        var verify_num = 0;
        
        var algo = split_cookie[0];
        var bits = split_cookie[1];
        var input_text = split_cookie[2];
        var config = "";
        var text = "";
        var text_fax = "";
        var NumAry = new Array();
        var count = 0;
        
        console.log(cookie);
        console.log(input_text);
        
        if(split_cookie[0] == "LEA"){
            config = split_cookie[3];
            console.log(config);
        }
        
        if(algo == "LSH"){
            var findStr = "tt";
            var input = "C:\\Bitnami\\wampstack-7.1.20-1\\apache2\\htdocs\\SmartContract_RainbowTable\\Kcryptoforum_Smart_Contract_RainbowTable\\dapp\\LSH\\" + algo + "-" + bits + ".txt";
            
            var input_fax = "C:\\Bitnami\\wampstack-7.1.20-1\\apache2\\htdocs\\SmartContract_RainbowTable\\Kcryptoforum_Smart_Contract_RainbowTable\\dapp\\LSH\\" + algo + "-" + bits + "_fax.txt";
            
            document.writeln("Original input file<br>");
            inputFile(input);
            document.writeln("<br><br>");
            
            var split_txt = text.split('"\r\n"');
            var first_split = split_txt[0].split('"');
            split_txt[0] = first_split[1];
            var final_split = split_txt[split_txt.length - 1].split('"');
            split_txt[split_txt.length - 1] = final_split[0];
            
            
            for(var i =0; i<split_txt.length; i++){
                if(split_txt[i].indexOf(input_text) != -1){
                    document.writeln("Block input [" + i + "]" + ": " + split_txt[i] + "<br />");
                    NumAry[count++] = i;
                }
            }
            document.writeln("<br><br>");
            
            inputFile_Fax(input_fax);
            split_txt = text_fax.split('\r\n');
            
            for(var i=0; i<NumAry.length; i++){
                document.writeln("Hash output [" + NumAry[i] + "]" + ": " + split_txt[NumAry[i] + 1] + "<br />");
            }


        }else if(algo == "LEA"){
            var findStr = "tt";
            var input = "C:\\Bitnami\\wampstack-7.1.20-1\\apache2\\htdocs\\SmartContract_RainbowTable\\Kcryptoforum_Smart_Contract_RainbowTable\\dapp\\LEA\\" + algo + "_" + config + "-" + bits + ".txt";
            var input_fact = "C:\\Bitnami\\wampstack-7.1.20-1\\apache2\\htdocs\\SmartContract_RainbowTable\\Kcryptoforum_Smart_Contract_RainbowTable\\dapp\\LEA\\" + algo + "_" + config + "-" + bits + "_fax.txt";
            
            document.writeln("Original input file<br>");
            inputFile(input);
            
            var split_txt = text.split('"\r\n"');
            
            for(var i =0; i<split_txt.length; i++){
                if(split_txt[i] == input_text){
                    document.writeln("<br />");
                    document.writeln(input_text + "is already exist");
                    
                    verify_num = 1;
                }
                
                if(split_txt[i].indexOf(findStr) != -1){
                    console.log(split_txt[i] + " find!!");
                }
            }
            
            
            if(verify_num == 0){
                NotExist();
                
                document.writeln("<br /><br />");
                document.writeln("Newest input file<br>");

                inputFile(input);
            }else {
                alert("You can not put new block");
            }
            
            $(window).ready(function(){
                console.log("load");

            });    
        }
        
        function inputFile(input){
            var fso = new ActiveXObject("Scripting.FileSystemObject");    
            var ForReading = 1;
            var f1 = fso.OpenTextFile(input, ForReading);
            text = f1.ReadAll();
            document.writeln(text);
            f1.close();
            return text;
        }
        
        function inputFile_Fax(input){
            var fso = new ActiveXObject("Scripting.FileSystemObject");    
            var ForReading = 1;
            var f1 = fso.OpenTextFile(input, ForReading);
            text_fax = f1.ReadAll();
            f1.close();
            return text_fax;
        }
        
        function NotExist(){
            var fileObject = new ActiveXObject("Scripting.FileSystemObject");
            
            if(algo == "LSH"){
                fWrite = fileObject.CreateTextFile("C:\\Bitnami\\wampstack-7.1.20-1\\apache2\\htdocs\\SmartContract_RainbowTable\\Kcryptoforum_Smart_Contract_RainbowTable\\dapp\\LSH\\" + algo + "-" + bits + ".txt", true);    
                
                fWrite.write("Algo_ID = LSH-" + bits);
                fWrite.write("\r\n");
                
                var count = split_txt.length + 1;
                
                fWrite.write("Message = " + count);
                fWrite.write("\r\n");
                
            }else if(algo == "LEA"){
                fWrite = fileObject.CreateTextFile("C:\\Bitnami\\wampstack-7.1.20-1\\apache2\\htdocs\\SmartContract_RainbowTable\\Kcryptoforum_Smart_Contract_RainbowTable\\dapp\\LEA\\" + algo + "_" + config + "-" + bits + ".txt", true);    
                
                fWrite.write("Algo_ID = LEA_" + config + "-" + bits);
                fWrite.write("\r\n");
            }

            for(var i=0; i<split_txt.length; i++){
                fWrite.write('"' + split_txt[i] + '"');
                fWrite.write("\r\n");
            }
            
            fWrite.write('"' + input_text + '"');

            fWrite.close();
        }
    </script>
</body>
</html>
