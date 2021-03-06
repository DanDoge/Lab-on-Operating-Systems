<!DOCTYPE html>
<html lang="zh-CN">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <link rel="stylesheet" href="./css/bootstrap.css">
  <link rel="stylesheet" href="./css/special-effects.css">
  <link rel="stylesheet" href="./css/main.css">
  <link rel="stylesheet" media="(max-width: 768px)" href="./css/mobile.css">
  <link rel="shortcut icon" href="./img/icon.ico" type="image/x-icon">
  <script type="text/javascript" src="./js/jquery.js"></script>
  <script type="text/javascript" src="./js/bootstrap.js"></script>
  <script type="text/javascript" src="./js/main.js"></script>
  <title>DanD的后花园</title>
</head>
<body>
  <nav class="navbar navbar-default navbar-fixed-top">
    <div class="container">
      <div class="navbar-header">
        <button type="button" class="navbar-toggle collapsed" data-toggle="collapse"
                data-target="#navbar-header" aria-expanded="false">
          <span class="sr-only">Toggle navigation</span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
        </button>
        <a class="navbar-brand logo" href="#">DanD的后花园</a>
      </div>
      <div class="collapse navbar-collapse" id="navbar-header">
        <ul class="nav navbar-nav">
          <li class="active"><a href="#">首页 <span class="sr-only">(current)</span></a></li>
          <li><a href="./article-list/all-article.html">文章列表</a></li>
          <li class="dropdown">
            <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button"
               aria-haspopup="true" aria-expanded="false">文章标签 <span class="caret"></span></a>
            <ul class="dropdown-menu">
              <li><a href="./article-list/qseudo-tech.html">(伪)技术</a></li>
              <li><a href="./article-list/foreign-lang.html">洋文学习</a></li>
              <li><a href="./Lychee">图床</a></li>
              <li><a href="http://47.93.217.74:2333">网盘</a></li>
              <li><a href="./oslab.html">操统实习</li>
              <li role="separator" class="divider"></li>
              <li class="disabled"><a href="#">读书笔记</a></li>
              <li role="separator" class="divider"></li>
            </ul>
          </li>
        </ul>
        <ul class = "visible-xs nav navbar-nav">
          <li class = "dropdown">
            <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button"
               aria-haspopup="true" aria-expanded="false">关于我 <span class="caret"></span></a>
            <ul class = "dropdown-menu">
              <div class="caption caption-xs">
                <h3>黄艺涵</h3>
                <div class="border-top padding-5px">
                  <li class="margin-1px" style="list-style-type:none">
                    <svg aria-hidden="true" class="octicon" height="16" version="1.1" viewBox="0 0 16 16" width="16">
                      <path fill="#6a737d" fill-rule="evenodd" d="M16 12.999c0 .439-.45 1-1 1H7.995c-.539 0-.994-.447-.995-.999H1c-.54 0-1-.561-1-1 0-2.634 3-4 3-4s.229-.409 0-1c-.841-.621-1.058-.59-1-3 .058-2.419 1.367-3 2.5-3s2.442.58 2.5 3c.058 2.41-.159 2.379-1 3-.229.59 0 1 0 1s1.549.711 2.42 2.088C9.196 9.369 10 8.999 10 8.999s.229-.409 0-1c-.841-.62-1.058-.59-1-3 .058-2.419 1.367-3 2.5-3s2.437.581 2.495 3c.059 2.41-.158 2.38-1 3-.229.59 0 1 0 1s3.005 1.366 3.005 4"></path>
                    </svg>
                    <span>
                      Peking University
                    </span>
                  </li>
                  <li class="margin-1px" style="list-style-type:none">
                    <svg aria-hidden="true" class="octicon" height="16" version="1.1" viewBox="0 0 12 16" width="12">
                      <path fill="#6a737d" fill-rule="evenodd" d="M6 0C2.69 0 0 2.5 0 5.5 0 10.02 6 16 6 16s6-5.98 6-10.5C12 2.5 9.31 0 6 0zm0 14.55C4.14 12.52 1 8.44 1 5.5 1 3.02 3.25 1 6 1c1.34 0 2.61.48 3.56 1.36.92.86 1.44 1.97 1.44 3.14 0 2.94-3.14 7.02-5 9.05zM8 5.5c0 1.11-.89 2-2 2-1.11 0-2-.89-2-2 0-1.11.89-2 2-2 1.11 0 2 .89 2 2z"></path>
                    </svg>
                    <span>
                      Beijing, China
                    </span>
                  </li>
                </div>
              </div>
            </ul>
          </li>
        </ul>
        <ul class="nav navbar-nav navbar-right">
          <li class="dropdown">
            <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button"
               aria-haspopup="true" aria-expanded="false">网络测试/外链 <span class="caret"></span></a>
            <ul class="dropdown-menu">
              <li><a href="./tz.php" target="_blank">探针</a></li>
              <li><a href="http://www.baidu.com" target="_blank">中国大陆</a></li>
              <li><a href="http://www.google.com.hk" target="_blank">国外</a></li>
              <li role="separator" class="divider"></li>
              <li><a href="https://jqfang.wordpress.com" target="_blank">The Secret Wonderland</a></li>
              <li><a href="./old/index.html" target="_blank">回到旧版</a></li>
            </ul>
          </li>
        </ul>
      </div>
    </div>
  </nav>
  <div class="main">
    <div class="container">
      <div class="about-me float-left col-sm-2 hidden-xs">
        <img src="./img/title.jpg" style="width: 100%; height: 100%; border-radius: 5px;">
        <div class="caption">
          <h3>黄艺涵</h3>
          <div class="border-top padding-5px">
            <li class="margin-1px" style="list-style-type:none">
              <svg aria-hidden="true" class="octicon" height="16" version="1.1" viewBox="0 0 16 16" width="16">
                <path fill="#6a737d" fill-rule="evenodd" d="M16 12.999c0 .439-.45 1-1 1H7.995c-.539 0-.994-.447-.995-.999H1c-.54 0-1-.561-1-1 0-2.634 3-4 3-4s.229-.409 0-1c-.841-.621-1.058-.59-1-3 .058-2.419 1.367-3 2.5-3s2.442.58 2.5 3c.058 2.41-.159 2.379-1 3-.229.59 0 1 0 1s1.549.711 2.42 2.088C9.196 9.369 10 8.999 10 8.999s.229-.409 0-1c-.841-.62-1.058-.59-1-3 .058-2.419 1.367-3 2.5-3s2.437.581 2.495 3c.059 2.41-.158 2.38-1 3-.229.59 0 1 0 1s3.005 1.366 3.005 4"></path>
              </svg>
              <span>
                Peking University
              </span>
            </li>
            <li class="margin-1px" style="list-style-type:none">
              <svg aria-hidden="true" class="octicon" height="16" version="1.1" viewBox="0 0 12 16" width="12">
                <path fill="#6a737d" fill-rule="evenodd" d="M6 0C2.69 0 0 2.5 0 5.5 0 10.02 6 16 6 16s6-5.98 6-10.5C12 2.5 9.31 0 6 0zm0 14.55C4.14 12.52 1 8.44 1 5.5 1 3.02 3.25 1 6 1c1.34 0 2.61.48 3.56 1.36.92.86 1.44 1.97 1.44 3.14 0 2.94-3.14 7.02-5 9.05zM8 5.5c0 1.11-.89 2-2 2-1.11 0-2-.89-2-2 0-1.11.89-2 2-2 1.11 0 2 .89 2 2z"></path>
              </svg>
              <span>
                Beijing, China
              </span>
            </li>
          </div>
        </div>
      </div>
      <div class="article-list col-sm-10">
          <form class="form-horizontal" action="./delete_page.php">
            <div class="form-group">
              <label class="control-label col-sm-2" for="job_name">任务名字:</label>
              <div class="col-sm-10">
                <input type="text" class="form-control" name="job_name" placeholder="job name">
              </div>
            </div>

            <div class="form-group">
              <div class="col-sm-offset-2 col-sm-10">
                <button type="submit" class="btn btn-default">Submit</button>
              </div>
            </div>

            <?php
                $job_name = $_GET['job_name'];
                echo `python /var/www/master.py "delete" $job_name`;
                echo "<br>"
                echo "debug: python /var/www/master.py \"delete\" $job_name";
                echo "<br>"
                echo "delete $job_name";
            ?>


        </form>
      </div>
    </div>
  </div>
</body>
</html>
