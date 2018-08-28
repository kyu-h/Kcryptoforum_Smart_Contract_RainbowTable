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
    <p>Please click algorithm type and output bits.</p>
    <table style="">
      <tr>
        <th>Algorithm types</th>
        <th>Output Bits</th>  
      </tr>
      <tr>
        <td>
            <input type="radio" name="algo" value="LSH" checked="checked"> LSH<br>
            <input type="radio" name="algo" value="LEA"> LEA<br>
            <input type="radio" name="algo" value="HIGHT"> HIGHT<br>
            <input type="radio" name="algo" value="CHAM"> CHAM<br>
        </td>

        <td>
            <div id="POP_LSH">
                <input type="radio" name="bits" value="256_224" checked="checked"> 256_224<br>
                <input type="radio" name="bits" value="256_256"> 256_256<br>
                <input type="radio" name="bits" value="512_224"> 512_224<br>
                <input type="radio" name="bits" value="512_256"> 512_256<br>
                <input type="radio" name="bits" value="512_384"> 512_384<br>
                <input type="radio" name="bits" value="512_512"> 512_512
            </div>

            <div id="POP_LEA" style="display: none;">
                <input type="radio" name="bits" value="128" checked="checked"> 128<br>
                <input type="radio" name="bits" value="192"> 192<br>
                <input type="radio" name="bits" value="256"> 256
            </div>
        </td>  
      </tr>
    </table>
    <div id="LEA_Config" style="display: none;">
        <table>
            <th>Config Mode</th>
            <td>
                <input type="radio" name="config" value="ECB" checked="checked"> ECB<br>
                <input type="radio" name="config" value="CBC"> CBC<br>
                <input type="radio" name="config" value="CTR"> CTR
            </td>
        </table>
    </div>
    
    <div>
        Input values : <input type="text" name="input_text" id="input_text">
        <input type = "button" id="button1" value="Send to Server" onclick="click_btn()">
    </div>
    
    <form method="POST">
        <input type = "button" id="button2" value="verify" onclick="verify()">
    </form>

    <br><br>
    
    <script>
        if (typeof web3 !== 'undefined') {
          web3 = new Web3(web3.currentProvider);
        } else {
          // set the provider you want from Web3.providers
          web3 = new Web3(new Web3.providers.HttpProvider("http://localhost:8545"));
        }
        
        var network_version = web3.version.network;
        console.log(network_version);
        
        var accounts = web3.eth.accounts;  //get account info
        var from_account = accounts[0];
        var to_account = accounts[1];
        
        var coinbase = web3.eth.coinbase;
        var balance = web3.fromWei(web3.eth.getBalance(coinbase), 'ether');
        
        console.log(coinbase);
        console.log(balance.c); //check ether in the coinbase 
        
        console.log(from_account);
        console.log(to_account);
        
        var transactionObj = { //transaction object setting
            from: from_account,
            to:to_account,
            value: 10000000
        };
        
        //web3.eth.sendTransaction(transactionObj);
    </script>
    
    <script>
        var get_cookie = document.cookie;
        var split_cookie = get_cookie.split('/');
        var algo = split_cookie[0];
        console.log(algo);
        
        if(algo == 'LEA'){
            console.log(algo+"!!!");
            window.onload = function() {
                $("input:radio[name='algo']:radio[value='LEA']").prop("checked", true);
                $("input:radio[name='algo']:radio[value='LSH']").prop("checked", false);
                $("input:radio[name='algo']:radio[value='HIGHT']").prop("checked", false);
                $("input:radio[name='algo']:radio[value='CHAM']").prop("checked", false);
                
                $('#POP_LSH').css('display', 'none');
                $('#POP_LEA').css('display', 'block');
                
                $('#LEA_Config').css('display', 'block');
            }
        }else if(algo == "LSH"){
            console.log(algo+"!!!");
            window.onload = function() {
                $("input:radio[name='algo']:radio[value='LEA']").prop("checked", false);
                $("input:radio[name='algo']:radio[value='LSH']").prop("checked", true);
                $("input:radio[name='algo']:radio[value='HIGHT']").prop("checked", false);
                $("input:radio[name='algo']:radio[value='CHAM']").prop("checked", false);
                
                $('#POP_LSH').css('display', 'none');
                $('#POP_LEA').css('display', 'block');
                
                $('#LEA_Config').css('display', 'none');
            }
        }
        
        
    </script>
    
    <script>
        var AlgoradioVal = $(':radio[name="algo"]:checked').val();
        var BitsradioVal = $(':radio[name="bits"]:checked').val();
        var config_mode = $(':radio[name="config"]:checked').val();
        var input_text = $('input[name=input_text]').val();
        
        
        console.log(input_text);
        
        function click_btn(){
            
            location.reload();
        }
        
        function verify(){
            var cookie = "";
            
            if(config_mode != null){
                cookie = AlgoradioVal + "/" + BitsradioVal + "/" + input_text + "/" + config_mode;
            }else {
                cookie = AlgoradioVal + "/" + BitsradioVal + "/" + input_text;
            }
            
            console.log(cookie);
            
            document.cookie = cookie;
            window.location.href = "/crowdfund_exercise_2/dapp/verify.php";
        }
        
        $('input[type=radio][name=algo]').on('click', function() {
            var chkvalue = $('input[type=radio][name=algo]:checked').val();

            if (chkvalue == 'LSH'){
                $('#POP_LSH').css('display', 'block');
                $('#POP_LEA').css('display', 'none');
                
                $('#uploadForm_LSH').css('display', 'block');
                $('#uploadForm_LEA').css('display', 'none');
                
                $('#LEA_Config').css('display', 'none');
                console.log(input_text);
            }else if(chkvalue == 'LEA'){
                $('#POP_LSH').css('display', 'none');
                $('#POP_LEA').css('display', 'block');
                
                $('#uploadForm_LSH').css('display', 'none');
                $('#uploadForm_LEA').css('display', 'block');
                
                $('#LEA_Config').css('display', 'block');
            }else if(chkvalue == 'HIGHT'){
                $('#POP_LSH').css('display', 'block');
                $('#POP_LEA').css('display', 'none');
                
                $('#uploadForm_LSH').css('display', 'block');
                $('#uploadForm_LEA').css('display', 'none');
                
                $('#LEA_Config').css('display', 'none');
            }else if(chkvalue == 'CHAM'){
                $('#POP_LSH').css('display', 'block');
                $('#POP_LEA').css('display', 'none');
                
                $('#uploadForm_LSH').css('display', 'block');
                $('#uploadForm_LEA').css('display', 'none');
                
                $('#LEA_Config').css('display', 'none');
            }
        });
    
    </script>

</body>
</html>
