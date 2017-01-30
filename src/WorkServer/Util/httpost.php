<?php

header("content-type:text/html;charset=utf-8");

if(empty($_GET))
{
    echo "{\"status\":-2,\"value\":\"GET请求为空\"}";
    exit();
}

if(empty($_GET['sid']))
{
    echo "{\"status\":-2,\"value\":\"学号不能为空\"}";
    exit();
}

if(empty($_GET['passwd']))
{
    echo "{\"status\":-2,\"value\":\"密码不能为空\"}";
    exit();
}

$sid = $_GET['sid'];
$passwd = $_GET['passwd'];

if( ((preg_match('/[0-2][0-9]1[2-6]\d{4}/', $sid)) == FALSE) || (strlen($sid) != 8) )
{

    echo "{\"status\":-2,\"value\":\"输入帐号长度有问题\"}";
}

if( strlen($passwd) < 6 || strlen($passwd) > 16 )
{
    echo "{\"status\":-2,\"value\":\"输入密码长度有问题\"}";
}

//get请求得到id,passwd,前期判断


$req_head = array(
    "Accept" => "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8",
    "Accept-Encoding" => "gzip, deflate",
    "Accept-Language" => "zh-CN,zh;q=0.8",
    "ache-Control" => "no-cache",
    "Connection" => "keep-alive",
    "Content-Type" => "application/x-www-form-urlencoded",
    "Host" => "222.24.62.120",
    "Origin" => "http://222.24.62.120",
    "Pragma" => "no-cache",
    "Referer" => "http://222.24.62.120/default4.aspx",
    "Upgrade-Insecure-Requests" => "1",
    "User-Agent" => "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.82 Safari/537.36",
);

//定义字符串数组$req_head,添加所有信息

$form_data =  "__VIEWSTATE=dDwxMTE4MjQwNDc1Ozs%2BYofaNxf5dpXqcC3ZAqYdKfPCdbw%3D&TextBox1=".$sid."&TextBox2=".$passwd."&RadioButtonList1=%D1%A7%C9%FA&Button1=+%B5%C7+%C2%BC+";


$to_url = "http://222.24.62.120/default4.aspx";

//定义请求的$form_data

$curl = curl_init();

//$curl = curl_init();

$cookie = "cookie";

if($curl)
{
    curl_setopt($curl, CURLOPT_HEADER, true);

    curl_setopt($curl, CURLOPT_POST, 1);

    curl_setopt($curl, CURLOPT_HTTPHEADER, $req_head);

    curl_setopt($curl, CURLOPT_COOKIEJAR, $cookie);

    curl_setopt($curl, CURLOPT_POSTFIELDS, $form_data);

    curl_setopt($curl, CURLOPT_URL, $to_url);

    $res = curl_exec($curl);

    $httpCode = curl_getinfo($curl, CURLINFO_HTTP_CODE);

    curl_close($curl);
    if($httpCode == 302)
    {
        $mes = "http://222.24.62.120/lw_xsxx.aspx?xh=".$sid;

        $req_head2 = array(
            "Accept" => "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8",
            "Accept-Encoding" => "gzip, deflate, sdch",
            "Accept-Language" => "zh-CN,zh;q=0.8,en;q=0.6,ia;q=0.4",
            "Cache-Control" => "no-cache",
            "Connection" => "keep-alive",
            "Host" => "222.24.62.120",
            "Pragma" => "no-cache",
            "Upgrade-Insecure-Requests" => "1",
            "User-Agent" => "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.82 Safari/537.36",
        );

        $curl2 = curl_init();

        if($curl2)
        {

            curl_setopt($curl2, CURLOPT_RETURNTRANSFER, 1);
            curl_setopt($curl2, CURLOPT_HEADER, false);
            curl_setopt($curl2, CURLOPT_NOBODY, false);
            curl_setopt($curl2, CURLOPT_HTTPGET, true);
            curl_setopt($curl2, CURLOPT_HTTPHEADER, $req_head2);
            curl_setopt($curl2, CURLOPT_COOKIEFILE, $cookie);
            curl_setopt($curl2, CURLOPT_REFERER, $mes);
            curl_setopt($curl2, CURLOPT_URL, $mes);

            $res2 = curl_exec($curl2);

            $httpCode2 = curl_getinfo($curl2, CURLINFO_HTTP_CODE);

            if($httpCode2 == 200)
            {
                $res2 = mb_convert_encoding($res2, "UTF-8","GB2312");
                $tmp = htmlentities($res2, ENT_QUOTES, 'UTF-8');
                echo "<pre>".$tmp."</pre><hr />";
    
                $dom = new DOMDocument();
                $dom ->loadHTML("<meta http-equiv=\"Content-Type\" content=\"text/html;charset=utf-8\">".$res2);
    
                $user = array();
    
                $user['xh'] = $dom->getElementById('xh')->nodeValue;
                $user['xm'] = $dom->getElementById('xm')->nodeValue;
                $user['xy'] = $dom->getElementById('xy')->nodeValue;
                $user['zy'] = $dom->getElementById('zy')->nodeValue;
                $user['xzb'] = $dom->getElementById('xzb')->nodeValue;

                       
                echo json_encode($user,JSON_UNESCAPED_UNICODE);   //发送json串
    
                curl_close($curl2);
            }
        }    
    }
}

