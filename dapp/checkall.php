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
        var inputext = "";
        var outputext = "";
        
        console.log(cookie);
        console.log(input_text);
        
        if(split_cookie[0] == "LEA"){
            config = split_cookie[2];
            console.log(config);
        }
        
        if(algo == "LSH"){
            var input = "C:\\Bitnami\\wampstack-7.1.20-1\\apache2\\htdocs\\SmartContract_RainbowTable\\Kcryptoforum_Smart_Contract_RainbowTable\\dapp\\LSH\\" + algo + "-" + bits + ".txt";
            
            var input_fact = "C:\\Bitnami\\wampstack-7.1.20-1\\apache2\\htdocs\\SmartContract_RainbowTable\\Kcryptoforum_Smart_Contract_RainbowTable\\dapp\\LSH\\" + algo + "-" + bits + "_fax.txt";
                
        <?php
            $current = "";
            $answer = "";

            putenv("PATH=C:\\Program Files (x86)\\mingw-w64\\i686-7.3.0-posix-dwarf-rt_v5-rev0\\mingw32\\bin");

            shell_exec("gcc -c main.c");
            shell_exec("gcc -c lsh.c");
            shell_exec("gcc -c lsh256.c");
            shell_exec("gcc -c lsh512.c");

            shell_exec("gcc -o main.exe main.o lsh.o lsh256.o lsh512.o");

            $answer = shell_exec("main.exe");
        ?>
            
            document.writeln("Input file<br>");
            inputFile(input);
            
            document.writeln("<br /><br />");
            document.writeln("Newest fact file<br>");
            outputFile(input_fact);


        }else if(algo == "LEA"){
            var input = "C:\\Bitnami\\wampstack-7.1.20-1\\apache2\\htdocs\\SmartContract_RainbowTable\\Kcryptoforum_Smart_Contract_RainbowTable\\dapp\\LEA\\" + algo + "_" + config + "-" + bits + ".txt";
            
            var input_fact = "C:\\Bitnami\\wampstack-7.1.20-1\\apache2\\htdocs\\SmartContract_RainbowTable\\Kcryptoforum_Smart_Contract_RainbowTable\\dapp\\LEA\\" + algo + "_" + config + "-" + bits + "_fax.txt";
            
            document.writeln("Input file<br>");
            inputFile(input);
            
        <?php
            $current = "";
            $answer = "";

            putenv("PATH=C:\\Program Files (x86)\\mingw-w64\\i686-7.3.0-posix-dwarf-rt_v5-rev0\\mingw32\\bin");

            shell_exec("gcc -c LEA_Main.c");
            shell_exec("gcc -c LEA_Default.c");
            shell_exec("gcc -c LEA_ConfigMode.c");

            shell_exec("gcc -o LEA_Main.exe LEA_Main.o LEA_Default.o LEA_ConfigMode.o");

            $answer = shell_exec("LEA_Main.exe");
        ?>

            document.writeln("<br /><br />");
            document.writeln("Newest fact file<br>");
            outputFile(input_fact);
        }
        
        function inputFile(input){
            var fso = new ActiveXObject("Scripting.FileSystemObject");    
            var ForReading = 1;
            var f1 = fso.OpenTextFile(input, ForReading);
            inputext = f1.ReadAll();
            document.writeln(inputext);
            f1.close();
            return inputext;
        }
        
        function outputFile(input){
            var fso = new ActiveXObject("Scripting.FileSystemObject");    
            var ForReading = 1;
            var f1 = fso.OpenTextFile(input, ForReading);
            outputext = f1.ReadAll();
            document.writeln(outputext);
            f1.close();
            return outputext;
        }
        
    </script>
    
</body>
</html>
