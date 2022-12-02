

<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="utf-8">
    <link rel="canonical" href="https://blog.csdn.net/weixin_50964512/article/details/123743421"/>
    <meta http-equiv="content-type" content="text/html; charset=utf-8">
    <meta name="renderer" content="webkit"/>
    <meta name="force-rendering" content="webkit"/>
    <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"/>
    <meta name="viewport" content="width=device-width, initial-scale=1.0, minimum-scale=1.0, maximum-scale=1.0, user-scalable=no">
    <meta name="report" content='{"pid": "blog", "spm":"1001.2101"}'>
    <meta name="referrer" content="always">
    <meta http-equiv="Cache-Control" content="no-siteapp" /><link rel="alternate" media="handheld" href="#" />
    <meta name="shenma-site-verification" content="5a59773ab8077d4a62bf469ab966a63b_1497598848">
    <meta name="applicable-device" content="pc">
    <link  href="https://g.csdnimg.cn/static/logo/favicon32.ico"  rel="shortcut icon" type="image/x-icon" />
    <title>C/C++网络编程详解（Windows版）_余识-的博客-CSDN博客_c++网络编程</title>
    <script>
      (function(){ 
        var el = document.createElement("script"); 
        el.src = "https://s3a.pstatp.com/toutiao/push.js?1abfa13dfe74d72d41d83c86d240de427e7cac50c51ead53b2e79d40c7952a23ed7716d05b4a0f683a653eab3e214672511de2457e74e99286eb2c33f4428830"; 
        el.id = "ttzz"; 
        var s = document.getElementsByTagName("script")[0]; 
        s.parentNode.insertBefore(el, s);
      })(window)
    </script>
        <meta name="keywords" content="c++网络编程">
        <meta name="csdn-baidu-search"  content='{"autorun":true,"install":true,"keyword":"c++网络编程"}'>
    <meta name="description" content="简析一个最简单的服务器和客户端怎么写，以及相关网络函数的常用方法">
    <script src="//g.csdnimg.cn/tingyun/1.8.5/blog.js" type='text/javascript'></script>
        <link rel="stylesheet" type="text/css" href="https://csdnimg.cn/release/blogv2/dist/pc/css/detail_enter-20b84432bf.min.css">
    <script type="application/ld+json">{"@context":"https://ziyuan.baidu.com/contexts/cambrian.jsonld","@id":"https://blog.csdn.net/weixin_50964512/article/details/123743421","appid":"1638831770136827","pubDate":"2022-03-25T19:16:31","title":"C/C++网络编程详解（Windows版）_余识-的博客-CSDN博客_c++网络编程","upDate":"2022-03-27T09:32:35"}</script>
        <link rel="stylesheet" type="text/css" href="https://csdnimg.cn/release/blogv2/dist/pc/themesSkin/skin-technology/skin-technology-a1f8f1d1b8.min.css">
    <script src="https://csdnimg.cn/public/common/libs/jquery/jquery-1.9.1.min.js" type="text/javascript"></script>
    <script type="text/javascript">
        var isCorporate = false;//注释删除enterprise
        var username =  "weixin_50964512";
        var skinImg = "white";
        var blog_address = "https://blog.csdn.net/weixin_50964512";
        var currentUserName = "cdcodecd";
        var isOwner = false;
        var loginUrl = "http://passport.csdn.net/account/login?from=https://blog.csdn.net/weixin_50964512/article/details/123743421";
        var blogUrl = "https://blog.csdn.net/";
        var avatar = "https://profile.csdnimg.cn/4/4/B/3_weixin_50964512";
        var articleTitle = "C/C++网络编程详解（Windows版）";
        var articleDesc = "简析一个最简单的服务器和客户端怎么写，以及相关网络函数的常用方法";
        var articleTitles = "C/C++网络编程详解（Windows版）_余识-的博客-CSDN博客_c++网络编程";
        var nickName = "余识-";
        var articleDetailUrl = "https://blog.csdn.net/weixin_50964512/article/details/123743421";
        if(window.location.host.split('.').length == 3) {
            blog_address = blogUrl + username;
        }
        var skinStatus = "White";
        var blogStaticHost = "https://csdnimg.cn/release/blogv2/"
        var mallTestStyle = "control"
    </script>
    <script src="https://g.csdnimg.cn/??fixed-sidebar/1.1.6/fixed-sidebar.js" type="text/javascript"></script>
    <script src='//g.csdnimg.cn/common/csdn-report/report.js' type='text/javascript'></script>
    <link rel="stylesheet" type="text/css" href="https://csdnimg.cn/public/sandalstrap/1.4/css/sandalstrap.min.css">
    <style>
        .MathJax, .MathJax_Message, .MathJax_Preview{
            display: none
        }
    </style>
    <script src="https://dup.baidustatic.com/js/ds.js"></script>
</head>
  <body class="nodata " style="">
        <script>
            var toolbarSearchExt = '{"landingWord":["c++网络编程"],"queryWord":"","tag":["c++","网络"],"title":"C/C++网络编程详解（Windows版）"}';
        </script>
    <script src="https://g.csdnimg.cn/common/csdn-toolbar/csdn-toolbar.js" type="text/javascript"></script>
    <script>
    (function(){
        var bp = document.createElement('script');
        var curProtocol = window.location.protocol.split(':')[0];
        if (curProtocol === 'https') {
            bp.src = 'https://zz.bdstatic.com/linksubmit/push.js';
        }
        else {
            bp.src = 'http://push.zhanzhang.baidu.com/push.js';
        }
        var s = document.getElementsByTagName("script")[0];
        s.parentNode.insertBefore(bp, s);
    })();
    </script>
<link rel="stylesheet" href="https://csdnimg.cn/release/blogv2/dist/pc/css/blog_code-01256533b5.min.css">
<link rel="stylesheet" href="https://csdnimg.cn/release/blogv2/dist/mdeditor/css/editerView/chart-3456820cac.css" />

<script>
    var articleId = 123743421;
    var commentscount = 3;
    var curentUrl = "https://blog.csdn.net/weixin_50964512/article/details/123743421";
    var myUrl = "https://my.csdn.net/";
    var highlight = ["windows","网络编程","c++","网络","详解","版"];//高亮数组
    var isRecommendModule = true;
    var isBaiduPre = true;
    var baiduCount = 2;
    var setBaiduJsCount = 10;
    var share_card_url = "https://app-blog.csdn.net/share?article_id=123743421&username=weixin_50964512"
	var articleType = 1;
    var baiduKey = "c++网络编程";
    var userNewReport = true;
    var needInsertBaidu = true;
    var recommendRegularDomainArr = ["blog.csdn.net/.+/article/details/","download.csdn.net/download/","edu.csdn.net/course/detail/","ask.csdn.net/questions/","bbs.csdn.net/topics/","www.csdn.net/gather_.+/"]
    var codeStyle = "tomorrow-night-eighties";
    var baiduSearchType = "baidulandingword";
     var sharData = "{\"hot\":[{\"id\":1,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/a5f4260710904e538002a6ab337939b3.png\"},{\"id\":2,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/188b37199a2c4b74b1d9ffc39e0d52de.png\"},{\"id\":3,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/14ded358b631444581edd98a256bc5af.png\"},{\"id\":4,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/1470f23a770444d986ad551b9c33c5be.png\"},{\"id\":5,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/c329f5181dc74f6c9bd28c982bb9f91d.png\"},{\"id\":6,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/ccd8a3305e81460f9c505c95b432a65f.png\"},{\"id\":7,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/bc89d8283389440d97fc4d30e30f45e1.png\"},{\"id\":8,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/452d485b4a654f5592390550d2445edf.png\"},{\"id\":9,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/f8b9939db2ed474a8f43a643015fc8b7.png\"},{\"id\":10,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/6de8864187ab4ed3b1db0856369c36ff.png\"},{\"id\":11,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/673cc3470ff74072acba958dc0c46e2d.png\"},{\"id\":12,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/930c119760ac4491804db80f9c6d4e3f.png\"},{\"id\":13,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/15e6befb05a24233bc2b65e96aa8d972.png\"},{\"id\":14,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/2075fd6822184b95a41e214de4daec13.png\"},{\"id\":15,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/859b1552db244eb6891a809263a5c657.png\"},{\"id\":16,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/0be2f920f1f74290a98921974a9613fd.png\"},{\"id\":17,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/2e97e00b43f14afab494ea55ef3f4a6e.png\"},{\"id\":18,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/ff4ab252f46e444686f5135d6ebbfec0.png\"},{\"id\":19,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/ae029bbe99564e79911657912d36524f.png\"},{\"id\":20,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/b3ece39963de440388728e9e7b9bf427.png\"},{\"id\":21,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/6f14651a99ba486e926d63b6fa692997.png\"},{\"id\":22,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/83ceddf050084875a341e32dcceca721.png\"},{\"id\":23,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/b90368b8fd5d4c6c8c79a707d877cf7c.png\"},{\"id\":24,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/aeffae14ecf14e079b2616528c9a393b.png\"},{\"id\":25,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/c5a06b5a13d44d16bed868fc3384897a.png\"},{\"id\":26,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/08b697658b844b318cea3b119e9541ef.png\"},{\"id\":27,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/68ccb0b8d09346ac961d2b5c1a8c77bf.png\"},{\"id\":28,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/a2227a247e37418cbe0ea972ba6a859b.png\"},{\"id\":29,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/3a42825fede748f9993e5bb844ad350d.png\"},{\"id\":30,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/8882abc1dd484224b636966ea38555c3.png\"},{\"id\":31,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/4f6a5f636a3e444d83cf8cc06d87a159.png\"},{\"id\":32,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/1953ef79c56b4407b78d7181bdff11c3.png\"},{\"id\":33,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/c04a2a4f772948ed85b5b0380ed36287.png\"},{\"id\":34,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/5b4fecd05091405ea04d8c0f53e9f2c7.png\"},{\"id\":35,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/b89f576d700344e280d6ceb2a66c2420.png\"},{\"id\":36,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/1c65780e11804bbd9971ebadb3d78bcf.png\"},{\"id\":37,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/d590db2055f345db9706eb68a7ec151a.png\"},{\"id\":38,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/fe602f80700b4f6fb3c4a9e4c135510e.png\"},{\"id\":39,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/39ff2fcd31e04feba301a071976a0ba7.png\"},{\"id\":40,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/f9b61b3d113f436b828631837f89fb39.png\"},{\"id\":41,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/df1aca5f610c4ad48cd16da88c9c8499.png\"},{\"id\":42,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/d7acf73a1e6b41399a77a85040e10961.png\"},{\"id\":43,\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/b7f1b63542524b97962ff649ab4e7e23.png\"}],\"vip\":[{\"id\":1,\"vipUrl\":\"https:\\/\\/img-home.csdnimg.cn\\/images\\/20220920101150.png\",\"url\":\"https:\\/\\/img-home.csdnimg.cn\\/images\\/20220920101154.png\"},{\"id\":2,\"vipUrl\":\"https:\\/\\/img-home.csdnimg.cn\\/images\\/20220920101204.png\",\"url\":\"https:\\/\\/img-home.csdnimg.cn\\/images\\/20220920101208.png\"},{\"id\":3,\"vipUrl\":\"https:\\/\\/img-home.csdnimg.cn\\/images\\/20220920101211.png\",\"url\":\"https:\\/\\/img-home.csdnimg.cn\\/images\\/20220920101215.png\"},{\"id\":4,\"vipUrl\":\"https:\\/\\/img-home.csdnimg.cn\\/images\\/20220920101218.png\",\"url\":\"https:\\/\\/img-home.csdnimg.cn\\/images\\/20220920101220.png\"},{\"id\":5,\"vipUrl\":\"https:\\/\\/img-home.csdnimg.cn\\/images\\/20220920101223.png\",\"url\":\"https:\\/\\/img-home.csdnimg.cn\\/images\\/20220920101226.png\"},{\"id\":6,\"vipUrl\":\"https:\\/\\/img-home.csdnimg.cn\\/images\\/20220922100635.png\",\"url\":\"https:\\/\\/img-home.csdnimg.cn\\/images\\/20220922100639.png\"},{\"id\":7,\"vipUrl\":\"https:\\/\\/img-home.csdnimg.cn\\/images\\/20220922100642.png\",\"url\":\"https:\\/\\/img-home.csdnimg.cn\\/images\\/20220922100644.png\"},{\"id\":8,\"vipUrl\":\"https:\\/\\/img-home.csdnimg.cn\\/images\\/20220922100647.png\",\"url\":\"https:\\/\\/img-home.csdnimg.cn\\/images\\/20220922100649.png\"},{\"id\":9,\"vipUrl\":\"https:\\/\\/img-home.csdnimg.cn\\/images\\/20220922100652.png\",\"url\":\"https:\\/\\/img-home.csdnimg.cn\\/images\\/20220922100655.png\"},{\"id\":10,\"vipUrl\":\"https:\\/\\/img-blog.csdnimg.cn\\/55de67481fde4b04b97ad78f11fe369a.png\",\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/bb2418fb537e4d78b10d8765ccd810c5.png\"},{\"id\":11,\"vipUrl\":\"https:\\/\\/img-blog.csdnimg.cn\\/579c713394584d128104ef1044023954.png\",\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/f420d9fbcf5548079d31b5e809b6d6cd.png\"},{\"id\":12,\"vipUrl\":\"https:\\/\\/img-blog.csdnimg.cn\\/75b7f3155ba642f5a4cc16b7baf44122.png\",\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/a9030f5877be401f8b340b80b0d91e64.png\"},{\"id\":13,\"vipUrl\":\"https:\\/\\/img-blog.csdnimg.cn\\/0903d33cafa54934be3780aa54ae958d.png\",\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/2cd8c8929f5a42fca5da2a0aeb456203.png\"},{\"id\":14,\"vipUrl\":\"https:\\/\\/img-blog.csdnimg.cn\\/949fd7c22884439fbfc3c0e9c3b8dee7.png\",\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/dafbea9bd9eb4f3b962b48dc41657f89.png\"},{\"id\":15,\"vipUrl\":\"https:\\/\\/img-blog.csdnimg.cn\\/4119cfddd71d4e6a8a27a18dbb74d90e.png\",\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/c56310c8b6384d9e85388e4e342ce508.png\"},{\"id\":16,\"vipUrl\":\"https:\\/\\/img-blog.csdnimg.cn\\/121575274da142bcbbbbc2e8243dd411.png\",\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/5013993de06542f881018bb9abe2edf7.png\"},{\"id\":17,\"vipUrl\":\"https:\\/\\/img-blog.csdnimg.cn\\/4d97aa6dd4fe4f09a6bef5bdf8a6abcd.png\",\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/76f23877b6ad4066ad45ce8e31b4b977.png\"},{\"id\":18,\"vipUrl\":\"https:\\/\\/img-blog.csdnimg.cn\\/fdb619daf21b4c829de63b9ebc78859d.png\",\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/a1abe5d27a5441f599adfe662f510243.png\"},{\"id\":19,\"vipUrl\":\"https:\\/\\/img-blog.csdnimg.cn\\/676b7707bb11410f8f56bc0ed2b2345c.png\",\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/7ac5b467fbf24e1d8c2de3f3332c4f54.png\"},{\"id\":20,\"vipUrl\":\"https:\\/\\/img-blog.csdnimg.cn\\/0becb8cc227e4723b765bdd69a20fd4a.png\",\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/fdec85b26091486b9a89d0b8d45c3749.png\"},{\"id\":21,\"vipUrl\":\"https:\\/\\/img-blog.csdnimg.cn\\/1a6c06235ad44941b38c54cbc25a370c.png\",\"url\":\"https:\\/\\/img-blog.csdnimg.cn\\/410a06cda2d44b0c84578f88275caf70.png\"}],\"map\":{\"hot\":\"热门\",\"vip\":\"VIP\"}}";
    
    var canRead = true;
    var blogMoveHomeArticle = false;
    var showPcWindowAd = false;
    var showHeadWord = true;
    var showSearchText = "";
    var linkPage = true;
    var articleSource = 1;
    var articleReport = '{"pid": "blog", "spm":"1001.2101"}';
    var isShowToQuestion = false;
    var baiduSearchChannel = 'pc_relevant'
    var baiduSearchIdentification = '.pc_relevant_multi_platform_whitelistv3'
    var distRequestId = '1669772314901_13200'
    var initRewardObject = {
        giver: "cdcodecd",
        anchor: "weixin_50964512",
        articleId: "123743421",
        sign: "4d07b15add252a9dbd2339ada633d9c3",
    }
    var isLikeStatus = false;
    var isUnLikeStatus = false;
    var studyLearnWord = "";
    var isCurrentUserVip = false;
    var testNewStyle = "oldStyle"
    var contentViewsHeight = 0;
    var contentViewsCount = 0;
    var contentViewsCountLimit = 5;
    var isShowConcision = true
    var isCookieConcision = false
    var isHasDirectoryModel = false
    var isShowSideModel = false
    var isShowDirectoryModel = true
    function getCookieConcision(sName){
        var allCookie = document.cookie.split("; ");
        for (var i=0; i < allCookie.length; i++){
            var aCrumb = allCookie[i].split("=");
            if (sName == aCrumb[0])
                return aCrumb[1];
        }
        return null;
    }
    if (getCookieConcision('blog_details_concision') && getCookieConcision('blog_details_concision') == 0){
        isCookieConcision = true
        isShowSideModel = true
        isShowDirectoryModel = false
    }
</script>
<div class="main_father clearfix d-flex justify-content-center mainfather-concision" style="height:100%;"> 
    <div class="container clearfix container-concision" id="mainBox">
        <script>
        if(!isCookieConcision){
            $('.main_father').removeClass('mainfather-concision')
            $('.main_father .container').removeClass('container-concision')
        }
        </script>
        <main>
<script type="text/javascript">
    function getQueryString(name) {   
      var reg = new RegExp("(^|&)" + name + "=([^&]*)(&|$)"); //构造一个含有目标参数的正则表达式对象  
      var r = window.location.search.substr(1).match(reg);  //匹配目标参数
      if( r != null ) return decodeURIComponent( r[2] ); return '';   
    }
    function stripscript(s){ 
      var pattern = new RegExp("[`~!@#$^&*()=|{}':;',\\[\\].<>/?~！@#￥……&*（）——|{}【】‘；：”“'。，、？%]") 
      var rs = ""; 
      for (var i = 0; i < s.length; i++) { 
        rs = rs+s.substr(i, 1).replace(pattern, ''); 
      } 
      return rs; 
    }
    var blogHotWords = stripscript(getQueryString('utm_term')).length > 1 ? stripscript(getQueryString('utm_term')) : ''
</script>
<div class="blog-content-box">
        <div class="article-header-box">
        <div class="article-header">
            <div class="article-title-box">
                <h1 class="title-article" id="articleContentId">C/C++网络编程详解（Windows版）</h1>
            </div>
            <div class="article-info-box">
                <div class="article-bar-top">
                    <img class="article-type-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/original.png" alt="">
                    <div class="bar-content">
                    <a class="follow-nickName " href="https://blog.csdn.net/weixin_50964512" target="_blank" rel="noopener">余识-</a>
                    <img class="article-time-img article-heard-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/newUpTime2.png" alt="">
                    <span class="time">已于&nbsp;2022-11-11 15:18:18&nbsp;修改</span>
                    <img class="article-read-img article-heard-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/articleReadEyes2.png" alt="">
                    <span class="read-count">7871</span>
                    <a id="blog_detail_zk_collection" class="un-collection" data-report-click='{"mod":"popu_823","spm":"1001.2101.3001.4232","ab":"new"}'>
                        <img class="article-collect-img article-heard-img un-collect-status isdefault" style="display:inline-block" src="https://csdnimg.cn/release/blogv2/dist/pc/img/tobarCollect2.png" alt="">
                        <img class="article-collect-img article-heard-img collect-status isactive" style="display:none" src="https://csdnimg.cn/release/blogv2/dist/pc/img/tobarCollectionActive2.png" alt="">
                        <span class="name">收藏</span>
                        <span class="get-collection">
                            198
                        </span>
                    </a>
                    </div>
                </div>
                <div class="blog-tags-box">
                    <div class="tags-box artic-tag-box">
                            <span class="label">分类专栏：</span>
                                <a class="tag-link" href="https://blog.csdn.net/weixin_50964512/category_11648675.html" target="_blank" rel="noopener">C++基础知识分享</a>
                            <span class="label">文章标签：</span>
                                <a data-report-click='{"mod":"popu_626","spm":"1001.2101.3001.4223","strategy":"c++","ab":"new","extra":"{\"searchword\":\"c++\"}"}' class="tag-link" href="https://so.csdn.net/so/search/s.do?q=c%2B%2B&amp;t=blog&amp;o=vip&amp;s=&amp;l=&amp;f=&amp;viparticle=" target="_blank" rel="noopener">c++</a>
                                <a data-report-click='{"mod":"popu_626","spm":"1001.2101.3001.4223","strategy":"网络","ab":"new","extra":"{\"searchword\":\"网络\"}"}' class="tag-link" href="https://so.csdn.net/so/search/s.do?q=%E7%BD%91%E7%BB%9C&amp;t=blog&amp;o=vip&amp;s=&amp;l=&amp;f=&amp;viparticle=" target="_blank" rel="noopener">网络</a>
                    </div>
                </div>
                <div class="up-time"><span>于&nbsp;2022-03-27 09:32:35&nbsp;首次发布</span></div>
                <div class="slide-content-box">
                    <div class="article-copyright">
                        <div class="creativecommons">
                            版权声明：本文为博主原创文章，遵循<a href="http://creativecommons.org/licenses/by-sa/4.0/" target="_blank" rel="noopener"> CC 4.0 BY-SA </a>版权协议，转载请附上原文出处链接和本声明。
                        </div>
                        <div class="article-source-link">
                            本文链接：<a href="https://blog.csdn.net/weixin_50964512/article/details/123743421" target="_blank">https://blog.csdn.net/weixin_50964512/article/details/123743421</a>
                        </div>
                    </div>
                </div>
                <div class="operating">
                    <a class="href-article-edit slide-toggle">版权</a>
                </div>
            </div>
        </div>
    </div>
    <div id="blogHuaweiyunAdvert"></div>
        <div id="blogColumnPayAdvert">
            <div class="column-group">
                <div class="column-group-item column-group0 column-group-item-one">
                    <div class="item-l">
                        <a class="item-target" href="https://blog.csdn.net/weixin_50964512/category_11648675.html" target="_blank" title="C++基础知识分享"
                        data-report-view='{"spm":"1001.2101.3001.6332"}'
                        data-report-click='{"spm":"1001.2101.3001.6332"}'>
                            <img class="item-target" src="https://img-blog.csdnimg.cn/20190918140037908.png?x-oss-process=image/resize,m_fixed,h_224,w_224" alt="">
                            <span class="title item-target">
                                <span>
                                <span class="tit">C++基础知识分享</span>
                                    <span class="dec">专栏收录该内容</span>
                                </span>
                            </span>
                        </a>
                    </div>
                    <div class="item-m">
                        <span>9 篇文章</span>
                        <span>16 订阅</span>
                    </div>
                    <div class="item-r">
                            <a class="item-target article-column-bt articleColumnFreeBt" data-id="11648675">订阅专栏</a>
                    </div>
                </div>
            </div>
        </div>
    <article class="baidu_pl">
        <div id="article_content" class="article_content clearfix">
        <link rel="stylesheet" href="https://csdnimg.cn/release/blogv2/dist/mdeditor/css/editerView/ck_htmledit_views-6e43165c0a.css">
                <div id="content_views" class="markdown_views prism-tomorrow-night-eighties">
                    <svg xmlns="http://www.w3.org/2000/svg" style="display: none;">
                        <path stroke-linecap="round" d="M5,0 0,2.5 5,5z" id="raphael-marker-block" style="-webkit-tap-highlight-color: rgba(0, 0, 0, 0);"></path>
                    </svg>
                    <p></p>
<div class="toc">
 <h3>文章目录</h3>
 <ul><li><a href="#_4">前言</a></li><li><a href="#_16">一、服务器</a></li><li><ul><li><a href="#WSAStartup_30">WSAStartup函数</a></li><li><ul><li><a href="#_31">正常使用</a></li><li><a href="#_58">函数详解</a></li></ul>
   </li><li><a href="#socket_77">socket函数</a></li><li><a href="#bind_103">bind函数</a></li><li><a href="#listen_130">listen函数</a></li><li><a href="#accept_151">accept函数</a></li><li><a href="#send_175">send函数</a></li><li><a href="#recv_198">recv函数</a></li><li><a href="#closesocket_221">closesocket函数</a></li><li><a href="#WSACleanup_229">WSACleanup函数</a></li></ul>
  </li><li><a href="#_303">二、客户端</a></li><li><ul><li><a href="#connect_313">connect函数</a></li></ul>
  </li><li><a href="#_386">三、其它网络相关函数</a></li><li><ul><li><a href="#htonsntohs_387">htons,ntohs等</a></li><li><a href="#inet_addrinet_ntoa_399">inet_addr&#xff0c;inet_ntoa</a></li><li><a href="#gethostbyname_411">gethostbyname</a></li><li><a href="#_426">注意事项</a></li></ul>
 </li></ul>
</div>
<p></p> 
<hr /> 
<h1><a id="_4"></a>前言</h1> 
<p>对学习C/C&#43;&#43;感兴趣的同学可以看看我的这篇文章哦&#xff1a;<a href="https://blog.csdn.net/weixin_50964512/article/details/125710864">C/C&#43;&#43;教程</a></p> 
<p>相比于基础&#xff0c;网络编程就要复杂一些&#xff0c;但其实也有固定格式&#xff0c;记住即可。</p> 
<p>首先是需要的头文件和库&#xff1a;</p> 
<pre><code class="prism language-cpp"><span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span><span class="token string">&lt;WinSock2.h&gt;</span></span>
<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">pragma</span> <span class="token expression"><span class="token function">comment</span><span class="token punctuation">(</span>lib<span class="token punctuation">,</span></span><span class="token string">&#34;ws2_32.lib&#34;</span><span class="token expression"><span class="token punctuation">)</span></span></span>
</code></pre> 
<h1><a id="_16"></a>一、服务器</h1> 
<p>主要流程及主要函数&#xff1a;</p> 
<ol><li>网络环境初始化&#xff1a;WSAStartup</li><li>创建服务器套接字&#xff1a;socket</li><li>绑定本机IP和端口&#xff1a;bind</li><li>监听客户端&#xff1a;listen</li><li>等待客户端连接&#xff1a;accept</li><li>发送消息&#xff1a;send</li><li>接收消息&#xff1a;recv</li><li>关闭socket&#xff1a;closesocket</li><li>清除网络环境&#xff1a;WSACleanup</li></ol> 
<h2><a id="WSAStartup_30"></a>WSAStartup函数</h2> 
<h3><a id="_31"></a>正常使用</h3> 
<p>函数原型&#xff1a;</p> 
<pre><code class="prism language-cpp"><span class="token keyword">int</span> <span class="token function">WSAStartup</span><span class="token punctuation">(</span>
WORD wVersionRequested<span class="token punctuation">,</span> <span class="token comment">//版本号&#xff0c;使用MAKEWORD宏生成</span>
LPWSADATA lpWSAData <span class="token comment">//数据</span>
<span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token comment">//返回值&#xff1a;0代表成功&#xff0c;否则失败</span>
</code></pre> 
<p>使用方法&#xff1a;</p> 
<pre><code class="prism language-cpp"><span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span><span class="token string">&lt;WinSock2.h&gt;</span></span>
<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span><span class="token string">&lt;iostream&gt;</span></span>
<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">pragma</span> <span class="token expression"><span class="token function">comment</span><span class="token punctuation">(</span>lib<span class="token punctuation">,</span></span><span class="token string">&#34;ws2_32&#34;</span><span class="token expression"><span class="token punctuation">)</span></span></span>
<span class="token keyword">using</span> <span class="token keyword">namespace</span> std<span class="token punctuation">;</span>
<span class="token keyword">int</span> <span class="token function">main</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
	WSADATA data<span class="token punctuation">;</span>
	<span class="token keyword">int</span> ret<span class="token operator">&#61;</span><span class="token function">WSAStartup</span><span class="token punctuation">(</span><span class="token function">MAKEWORD</span><span class="token punctuation">(</span><span class="token number">2</span><span class="token punctuation">,</span><span class="token number">2</span><span class="token punctuation">)</span><span class="token punctuation">,</span><span class="token operator">&amp;</span>data<span class="token punctuation">)</span><span class="token punctuation">;</span>
	<span class="token keyword">if</span> <span class="token punctuation">(</span>ret<span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
		cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;初始化网络错误&#xff01;&#34;</span> <span class="token operator">&lt;&lt;</span> endl<span class="token punctuation">;</span>
		<span class="token keyword">return</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>
	<span class="token punctuation">}</span>
<span class="token punctuation">}</span>
</code></pre> 
<p>该函数用于初始化网络环境&#xff0c;参数基本上是固定写法&#xff0c;记住即可&#xff0c;必须要有。</p> 
<h3><a id="_58"></a>函数详解</h3> 
<p>该函数实则是用来加载Windows Socket动态库的</p> 
<p>wVersionRequested参数用来指定准备加载动态库的版本号&#xff0c;高字节为库文件的副版本&#xff0c;低字节指定主版本&#xff0c;MAKEWORD(X,Y)宏用于生成该参数&#xff0c;其中X为高字节&#xff0c;Y为低字节</p> 
<p>lpWSAData 为指向WSADATA结构体的指针&#xff0c;该参数用于返回被加载动态库的有关信息</p> 
<pre><code class="prism language-cpp"><span class="token keyword">typedef</span> <span class="token keyword">struct</span> <span class="token class-name">WSAData</span> <span class="token punctuation">{<!-- --></span>
WORD  			wVersion<span class="token punctuation">;</span> <span class="token comment">//期望调用者使用的socket版本&#xff08;或实际返回的socket版本&#xff0c;可根据此参数判断返回的版本号是否正确&#xff0c;可通过HIBYTE宏取得高字节&#xff0c;LOBYTE宏取得低字节&#xff09;</span>
WORD  			wHighVersion<span class="token punctuation">;</span> <span class="token comment">//本机Dll支持的最高版本</span>
<span class="token keyword">unsigned</span> <span class="token keyword">short</span>  iMaxSockets<span class="token punctuation">;</span><span class="token comment">//一个进程最多可以打开的套接字数量&#xff08;2.0版本后忽略此值&#xff09;</span>
<span class="token keyword">unsigned</span> <span class="token keyword">short</span>  iMaxUdpDg<span class="token punctuation">;</span> <span class="token comment">//一个进程发送或接收的最大数据报长度</span>
<span class="token keyword">char</span> FAR <span class="token operator">*</span>   	lpVendorInfo<span class="token punctuation">;</span> <span class="token comment">//厂商专有信息&#xff08;2.0版本后忽略此值&#xff09;</span>
<span class="token keyword">char</span>    		szDescription<span class="token punctuation">[</span>WSADESCRIPTION_LEN<span class="token operator">&#43;</span><span class="token number">1</span><span class="token punctuation">]</span><span class="token punctuation">;</span> <span class="token comment">//DLL的描述信息</span>
<span class="token keyword">char</span>    		szSystemStatus<span class="token punctuation">[</span>WSASYS_STATUS_LEN<span class="token operator">&#43;</span><span class="token number">1</span><span class="token punctuation">]</span><span class="token punctuation">;</span><span class="token comment">//DLL的状态信息</span>
</code></pre> 
<h2><a id="socket_77"></a>socket函数</h2> 
<p>函数原型&#xff1a;</p> 
<pre><code class="prism language-cpp">SOCKET <span class="token function">socket</span><span class="token punctuation">(</span>
<span class="token keyword">int</span> af<span class="token punctuation">,</span>	<span class="token comment">//地址类型&#xff0c;常用IPv4地址&#xff1a;AF_INET&#xff0c;和IPv6地址&#xff1a;AF_INET6</span>
<span class="token keyword">int</span> type<span class="token punctuation">,</span> <span class="token comment">//套接字类型&#xff0c;常用TCP协议&#xff1a;SOCK_STREAM,UDP协议&#xff1a;SOCK_DGRAM</span>
<span class="token keyword">int</span> protocol <span class="token comment">//协议类型&#xff0c;一般填0&#xff0c;自动选择即可</span>
<span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token comment">//返回值&#xff0c;INVALID_SOCKET失败&#xff0c;该宏实则定义为-1&#xff0c;否则成功</span>
</code></pre> 
<p>使用&#xff1a;</p> 
<pre><code class="prism language-cpp">
SOCKET sock<span class="token operator">&#61;</span><span class="token function">socket</span><span class="token punctuation">(</span>AF_INET<span class="token punctuation">,</span>SOCK_STREAM<span class="token punctuation">,</span><span class="token number">0</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token keyword">if</span> <span class="token punctuation">(</span>sock <span class="token operator">&#61;&#61;</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
	cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;创建套接字失败&#34;</span><span class="token punctuation">;</span>
	<span class="token keyword">return</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>

</code></pre> 
<p>该代码创建了IPv4类型的地址&#xff0c;TCP协议的套接字</p> 
<p>完整视图&#xff1a;<br /> <img src="https://img-blog.csdnimg.cn/640f684844ce435b994047dc6a9756db.png?x-oss-process&#61;image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5L2Z6K-GLQ&#61;&#61;,size_20,color_FFFFFF,t_70,g_se,x_16" alt="在这里插入图片描述" /></p> 
<h2><a id="bind_103"></a>bind函数</h2> 
<p>函数原型&#xff1a;</p> 
<pre><code class="prism language-cpp"><span class="token keyword">int</span> <span class="token function">bind</span><span class="token punctuation">(</span> 
SOCKET s<span class="token punctuation">,</span> <span class="token comment">//创建的socket</span>
sockaddr <span class="token operator">*</span> name<span class="token punctuation">,</span> <span class="token comment">//包含地址和端口的结构体</span>
<span class="token keyword">int</span> namelen <span class="token comment">//sockaddr 结构长度</span>
<span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token comment">//返回值&#xff1a;返回SOCKET_ERROR失败&#xff0c;该宏被定义为-1&#xff0c;否则成功&#xff0c;返回值为0</span>
</code></pre> 
<p>使用&#xff1a;</p> 
<pre><code class="prism language-cpp"><span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">define</span> <span class="token macro-name">_WINSOCK_DEPRECATED_NO_WARNINGS</span> <span class="token comment">//vs环境下必须定义&#xff0c;否则无法使用inet_addr函数</span></span>
sockaddr_in addr<span class="token punctuation">;</span>
addr<span class="token punctuation">.</span>sin_family <span class="token operator">&#61;</span> AF_INET<span class="token punctuation">;</span> <span class="token comment">//地址为IPv4协议</span>
addr<span class="token punctuation">.</span>sin_port <span class="token operator">&#61;</span> <span class="token function">htons</span><span class="token punctuation">(</span><span class="token number">9999</span><span class="token punctuation">)</span><span class="token punctuation">;</span> <span class="token comment">//端口为9999</span>
addr<span class="token punctuation">.</span>sin_addr<span class="token punctuation">.</span>S_un<span class="token punctuation">.</span>S_addr <span class="token operator">&#61;</span> <span class="token function">inet_addr</span><span class="token punctuation">(</span><span class="token string">&#34;127.0.0.1&#34;</span><span class="token punctuation">)</span><span class="token punctuation">;</span> <span class="token comment">//具体绑定本机的地址</span>
ret<span class="token operator">&#61;</span><span class="token function">bind</span><span class="token punctuation">(</span>sock<span class="token punctuation">,</span><span class="token punctuation">(</span>sockaddr<span class="token operator">*</span><span class="token punctuation">)</span><span class="token operator">&amp;</span>addr<span class="token punctuation">,</span> <span class="token keyword">sizeof</span><span class="token punctuation">(</span>addr<span class="token punctuation">)</span><span class="token punctuation">)</span><span class="token punctuation">;</span> <span class="token comment">//绑定</span>
<span class="token keyword">if</span> <span class="token punctuation">(</span>ret <span class="token operator">&#61;&#61;</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
	cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;绑定地址端口失败&#34;</span><span class="token punctuation">;</span>
	<span class="token keyword">return</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>
</code></pre> 
<p>完整视图&#xff1a;<br /> <img src="https://img-blog.csdnimg.cn/1af344333ddf4c14a7200676cfb996c3.png?x-oss-process&#61;image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5L2Z6K-GLQ&#61;&#61;,size_20,color_FFFFFF,t_70,g_se,x_16" alt="在这里插入图片描述" /></p> 
<h2><a id="listen_130"></a>listen函数</h2> 
<p>函数原型&#xff1a;</p> 
<pre><code class="prism language-cpp"><span class="token keyword">int</span> <span class="token function">listen</span><span class="token punctuation">(</span>
SOCKET s<span class="token punctuation">,</span> <span class="token comment">//要监听的socket</span>
<span class="token keyword">int</span> backlog <span class="token comment">//等待连接的最大队列长度</span>
<span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token comment">//返回值&#xff1a;返回SOCKET_ERROR失败&#xff0c;该宏被定义为-1&#xff0c;否则成功&#xff0c;返回值为0</span>
</code></pre> 
<p>使用&#xff1a;</p> 
<pre><code class="prism language-cpp">ret<span class="token operator">&#61;</span><span class="token function">listen</span><span class="token punctuation">(</span>sock<span class="token punctuation">,</span><span class="token number">5</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token keyword">if</span> <span class="token punctuation">(</span>ret <span class="token operator">&#61;&#61;</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
	cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;监听套接字失败&#34;</span><span class="token punctuation">;</span>
	<span class="token keyword">return</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>
</code></pre> 
<p>完成代码&#xff1a;<br /> <img src="https://img-blog.csdnimg.cn/0a7971be2efe480684eb8eed5e040ef5.png?x-oss-process&#61;image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5L2Z6K-GLQ&#61;&#61;,size_20,color_FFFFFF,t_70,g_se,x_16" alt="在这里插入图片描述" /></p> 
<h2><a id="accept_151"></a>accept函数</h2> 
<p>函数原型&#xff1a;</p> 
<pre><code class="prism language-cpp">SOCKET <span class="token function">accept</span><span class="token punctuation">(</span>
SOCKET s<span class="token punctuation">,</span> <span class="token comment">//接收的socket</span>
sockaddr<span class="token operator">*</span> addr<span class="token punctuation">,</span> <span class="token comment">//接收到客户端的地址信息</span>
<span class="token keyword">int</span> <span class="token operator">*</span> addrlen <span class="token comment">//地址信息长度</span>
<span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token comment">//返回值&#xff1a;返回INVALID_SOCKET失败&#xff0c;该宏定义为-1&#xff0c;否则成功返回客户端的套接字&#xff0c;可进行发送和接收消息</span>
</code></pre> 
<p>使用&#xff1a;</p> 
<pre><code class="prism language-cpp">sockaddr addrCli<span class="token punctuation">;</span>
<span class="token keyword">int</span> len <span class="token operator">&#61;</span> <span class="token keyword">sizeof</span><span class="token punctuation">(</span>addrCli<span class="token punctuation">)</span><span class="token punctuation">;</span>
SOCKET sockCli<span class="token operator">&#61;</span><span class="token function">accept</span><span class="token punctuation">(</span>sock<span class="token punctuation">,</span><span class="token operator">&amp;</span>addrCli<span class="token punctuation">,</span><span class="token operator">&amp;</span>len<span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token keyword">if</span> <span class="token punctuation">(</span>sockCli <span class="token operator">&#61;&#61;</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
	cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;接收客户端连接失败&#34;</span><span class="token punctuation">;</span>
	<span class="token keyword">return</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>
</code></pre> 
<p>完整代码视图&#xff1a;<br /> <img src="https://img-blog.csdnimg.cn/1d9ac0c0878d46d0b36d756df5126847.png?x-oss-process&#61;image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5L2Z6K-GLQ&#61;&#61;,size_20,color_FFFFFF,t_70,g_se,x_16" alt="在这里插入图片描述" /></p> 
<h2><a id="send_175"></a>send函数</h2> 
<p>函数原型&#xff1a;</p> 
<pre><code class="prism language-cpp"><span class="token keyword">int</span> <span class="token function">send</span><span class="token punctuation">(</span>
SOCKET s<span class="token punctuation">,</span>
<span class="token keyword">char</span> <span class="token operator">*</span> buf<span class="token punctuation">,</span><span class="token comment">//要发送的内容</span>
<span class="token keyword">int</span> len<span class="token punctuation">,</span> <span class="token comment">//内容长度</span>
<span class="token keyword">int</span> flags <span class="token comment">//一般为0&#xff0c;拷贝到程序中就立即删除内核中的数据,或MSG_DONTROUTE:要求传输层不要将数据路由出去&#xff0c;MSG_OOB&#xff1a;标志数据应该被带外发送</span>
<span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token comment">//返回值&#xff1a;-1&#xff08;或宏SOCKET_ERROR&#xff09;表示发送失败&#xff0c;否则返回发送成功的字节数</span>
</code></pre> 
<p>使用&#xff1a;</p> 
<pre><code class="prism language-cpp"><span class="token keyword">char</span> buf<span class="token punctuation">[</span><span class="token number">0xFF</span><span class="token punctuation">]</span> <span class="token operator">&#61;</span> <span class="token string">&#34;我是服务器&#34;</span><span class="token punctuation">;</span>
ret<span class="token operator">&#61;</span><span class="token function">send</span><span class="token punctuation">(</span>sockCli<span class="token punctuation">,</span> buf<span class="token punctuation">,</span> <span class="token function">strlen</span><span class="token punctuation">(</span>buf<span class="token punctuation">)</span><span class="token punctuation">,</span><span class="token number">0</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token keyword">if</span> <span class="token punctuation">(</span>ret <span class="token operator">&#61;&#61;</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
	cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;发送信息失败&#34;</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>
</code></pre> 
<p>整体视图&#xff1a;<br /> <img src="https://img-blog.csdnimg.cn/9df275a0d2864a0aab3ddf2d240d4992.png?x-oss-process&#61;image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5L2Z6K-GLQ&#61;&#61;,size_20,color_FFFFFF,t_70,g_se,x_16" alt="在这里插入图片描述" /></p> 
<h2><a id="recv_198"></a>recv函数</h2> 
<p>函数原型&#xff1a;</p> 
<pre><code class="prism language-cpp"><span class="token keyword">int</span> <span class="token function">recv</span><span class="token punctuation">(</span>
SOCKET s<span class="token punctuation">,</span> <span class="token comment">//套接字</span>
 <span class="token keyword">char</span> <span class="token operator">*</span> buf<span class="token punctuation">,</span> <span class="token comment">//接受数据的缓存区</span>
<span class="token keyword">int</span> len<span class="token punctuation">,</span> <span class="token comment">//缓存区大小</span>
<span class="token keyword">int</span> flags <span class="token comment">//标志&#xff0c;一般填0&#xff0c;将消息拷贝到应用程序中&#xff0c;将内核中的数据删除&#xff0c;还可以填MSG_PEEK,只取数据&#xff0c;不从内核中删除数据&#xff0c;MSG_OOB&#xff1a;处理带外数据</span>
<span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token comment">//返回值&#xff1a;小于等于0都表示出错&#xff0c;大于0则表示接收成功的数据大小</span>
</code></pre> 
<p>使用&#xff1a;</p> 
<pre><code class="prism language-cpp">ret<span class="token operator">&#61;</span><span class="token function">recv</span><span class="token punctuation">(</span>sockCli<span class="token punctuation">,</span>buf<span class="token punctuation">,</span><span class="token number">0xFF</span><span class="token punctuation">,</span><span class="token number">0</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token keyword">if</span> <span class="token punctuation">(</span>ret <span class="token operator">&lt;&#61;</span> <span class="token number">0</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
	cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;接受客户端数据失败&#34;</span><span class="token punctuation">;</span>
	<span class="token keyword">return</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>
</code></pre> 
<p>完整视图&#xff1a;<br /> <img src="https://img-blog.csdnimg.cn/4c384500cd4f4020b1ef7a3193aa7de3.png?x-oss-process&#61;image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5L2Z6K-GLQ&#61;&#61;,size_17,color_FFFFFF,t_70,g_se,x_16" alt="在这里插入图片描述" /></p> 
<h2><a id="closesocket_221"></a>closesocket函数</h2> 
<pre><code class="prism language-cpp"><span class="token keyword">int</span> <span class="token function">closesocket</span><span class="token punctuation">(</span>
SOCKET s <span class="token comment">//要关闭的socket</span>
<span class="token punctuation">)</span><span class="token punctuation">;</span>
</code></pre> 
<p>该函数就是关闭不用的socket&#xff0c;释放资源</p> 
<h2><a id="WSACleanup_229"></a>WSACleanup函数</h2> 
<p>无任何参数&#xff0c;直接调用即可</p> 
<pre><code class="prism language-cpp"><span class="token function">WSACleanup</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
</code></pre> 
<p>按理说尽量在应用程序退出时都要进行清理&#xff0c;否则下次启动可能出现错误</p> 
<p>修改后的代码视图&#xff1a;<br /> <img src="https://img-blog.csdnimg.cn/e4fc7fee540c4b9eb8fd7998f1b1614e.png?x-oss-process&#61;image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5L2Z6K-GLQ&#61;&#61;,size_15,color_FFFFFF,t_70,g_se,x_16" alt="在这里插入图片描述" /><br /> 完整代码&#xff1a;</p> 
<pre><code class="prism language-cpp"><span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">define</span> <span class="token macro-name">_WINSOCK_DEPRECATED_NO_WARNINGS</span></span>
<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span><span class="token string">&lt;WinSock2.h&gt;</span></span>
<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">pragma</span> <span class="token expression"><span class="token function">comment</span><span class="token punctuation">(</span>lib<span class="token punctuation">,</span></span><span class="token string">&#34;ws2_32&#34;</span><span class="token expression"><span class="token punctuation">)</span></span></span>
<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span><span class="token string">&lt;iostream&gt;</span></span>
<span class="token keyword">using</span> <span class="token keyword">namespace</span> std<span class="token punctuation">;</span>
<span class="token keyword">int</span> <span class="token function">main</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
	WSADATA data<span class="token punctuation">;</span>
	<span class="token keyword">int</span> ret<span class="token operator">&#61;</span><span class="token function">WSAStartup</span><span class="token punctuation">(</span><span class="token function">MAKEWORD</span><span class="token punctuation">(</span><span class="token number">2</span><span class="token punctuation">,</span><span class="token number">2</span><span class="token punctuation">)</span><span class="token punctuation">,</span><span class="token operator">&amp;</span>data<span class="token punctuation">)</span><span class="token punctuation">;</span>
	<span class="token keyword">if</span> <span class="token punctuation">(</span>ret<span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
		cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;初始化网络错误&#xff01;&#34;</span> <span class="token operator">&lt;&lt;</span> endl<span class="token punctuation">;</span>
		<span class="token function">WSACleanup</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
		<span class="token keyword">return</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>
	<span class="token punctuation">}</span>
	SOCKET sock<span class="token operator">&#61;</span><span class="token function">socket</span><span class="token punctuation">(</span>AF_INET<span class="token punctuation">,</span>SOCK_STREAM<span class="token punctuation">,</span><span class="token number">0</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
	<span class="token keyword">if</span> <span class="token punctuation">(</span>sock <span class="token operator">&#61;&#61;</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
		cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;创建套接字失败&#34;</span><span class="token punctuation">;</span>
		<span class="token function">WSACleanup</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
		<span class="token keyword">return</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>
	<span class="token punctuation">}</span>
	sockaddr_in addr<span class="token punctuation">;</span>
	addr<span class="token punctuation">.</span>sin_family <span class="token operator">&#61;</span> AF_INET<span class="token punctuation">;</span>
	addr<span class="token punctuation">.</span>sin_port <span class="token operator">&#61;</span> <span class="token function">htons</span><span class="token punctuation">(</span><span class="token number">9999</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
	addr<span class="token punctuation">.</span>sin_addr<span class="token punctuation">.</span>S_un<span class="token punctuation">.</span>S_addr <span class="token operator">&#61;</span> <span class="token function">inet_addr</span><span class="token punctuation">(</span><span class="token string">&#34;127.0.0.1&#34;</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
	ret<span class="token operator">&#61;</span><span class="token function">bind</span><span class="token punctuation">(</span>sock<span class="token punctuation">,</span><span class="token punctuation">(</span>sockaddr<span class="token operator">*</span><span class="token punctuation">)</span><span class="token operator">&amp;</span>addr<span class="token punctuation">,</span> <span class="token keyword">sizeof</span><span class="token punctuation">(</span>addr<span class="token punctuation">)</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
	<span class="token keyword">if</span> <span class="token punctuation">(</span>ret <span class="token operator">&#61;&#61;</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
		cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;绑定地址端口失败&#34;</span><span class="token punctuation">;</span>
		<span class="token function">WSACleanup</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
		<span class="token keyword">return</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>
	<span class="token punctuation">}</span>
	ret<span class="token operator">&#61;</span><span class="token function">listen</span><span class="token punctuation">(</span>sock<span class="token punctuation">,</span><span class="token number">5</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
	<span class="token keyword">if</span> <span class="token punctuation">(</span>ret <span class="token operator">&#61;&#61;</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
		cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;监听套接字失败&#34;</span><span class="token punctuation">;</span>
		<span class="token function">WSACleanup</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
		<span class="token keyword">return</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>
	<span class="token punctuation">}</span>
	sockaddr addrCli<span class="token punctuation">;</span>
	<span class="token keyword">int</span> len <span class="token operator">&#61;</span> <span class="token keyword">sizeof</span><span class="token punctuation">(</span>addrCli<span class="token punctuation">)</span><span class="token punctuation">;</span>
	SOCKET sockCli<span class="token operator">&#61;</span><span class="token function">accept</span><span class="token punctuation">(</span>sock<span class="token punctuation">,</span><span class="token operator">&amp;</span>addrCli<span class="token punctuation">,</span><span class="token operator">&amp;</span>len<span class="token punctuation">)</span><span class="token punctuation">;</span>
	<span class="token keyword">if</span> <span class="token punctuation">(</span>sockCli <span class="token operator">&#61;&#61;</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
		cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;接收客户端连接失败&#34;</span><span class="token punctuation">;</span>
		<span class="token function">WSACleanup</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
		<span class="token keyword">return</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>
	<span class="token punctuation">}</span>
	<span class="token keyword">char</span> buf<span class="token punctuation">[</span><span class="token number">0xFF</span><span class="token punctuation">]</span> <span class="token operator">&#61;</span> <span class="token string">&#34;我是服务器&#34;</span><span class="token punctuation">;</span>
	ret<span class="token operator">&#61;</span><span class="token function">send</span><span class="token punctuation">(</span>sockCli<span class="token punctuation">,</span> buf<span class="token punctuation">,</span> <span class="token function">strlen</span><span class="token punctuation">(</span>buf<span class="token punctuation">)</span><span class="token punctuation">,</span><span class="token number">0</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
	<span class="token keyword">if</span> <span class="token punctuation">(</span>ret <span class="token operator">&#61;&#61;</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
		cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;发送信息失败&#34;</span><span class="token punctuation">;</span>
		<span class="token function">WSACleanup</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
		<span class="token keyword">return</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>
	<span class="token punctuation">}</span>
	ret<span class="token operator">&#61;</span><span class="token function">recv</span><span class="token punctuation">(</span>sockCli<span class="token punctuation">,</span>buf<span class="token punctuation">,</span><span class="token number">0xFF</span><span class="token punctuation">,</span><span class="token number">0</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
	<span class="token keyword">if</span> <span class="token punctuation">(</span>ret <span class="token operator">&lt;&#61;</span> <span class="token number">0</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
		cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;接受客户端数据失败&#34;</span><span class="token punctuation">;</span>
		<span class="token function">WSACleanup</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
		<span class="token keyword">return</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>
	<span class="token punctuation">}</span>
	<span class="token function">WSACleanup</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>
</code></pre> 
<p>至此&#xff0c;一个最简单的windows服务器就写好了&#xff0c;可以简单执行一次发送数据和一次接受数据。</p> 
<h1><a id="_303"></a>二、客户端</h1> 
<p>主要流程和函数&#xff1a;</p> 
<ol><li>初始化网络环境&#xff1a;WSAStartup</li><li>创建套接字&#xff1a;socket</li><li>连接服务器&#xff1a;connect</li><li>发送数据&#xff1a;send</li><li>接收数据&#xff1a;recv</li><li>清理网络环境&#xff1a;WSACleanup</li></ol> 
<p>其它三个函数与服务器一样&#xff0c;只是多出个connect函数&#xff0c;使用方法也与bind函数类似</p> 
<h2><a id="connect_313"></a>connect函数</h2> 
<p>函数原型&#xff1a;</p> 
<pre><code class="prism language-cpp"><span class="token keyword">int</span> <span class="token function">connect</span><span class="token punctuation">(</span>
SOCKET s<span class="token punctuation">,</span> <span class="token comment">//与服务器连接的socket</span>
sockaddr<span class="token operator">*</span> name<span class="token punctuation">,</span> <span class="token comment">//服务器的地址端口</span>
<span class="token keyword">int</span> namelen <span class="token comment">//上个参数结构体的长度</span>
<span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token comment">//返回值&#xff1a;-1失败&#xff0c;否则成功</span>
</code></pre> 
<p>使用方法&#xff1a;</p> 
<pre><code class="prism language-cpp">sockaddr_in addr<span class="token punctuation">;</span>
addr<span class="token punctuation">.</span>sin_family <span class="token operator">&#61;</span> AF_INET<span class="token punctuation">;</span>
addr<span class="token punctuation">.</span>sin_port <span class="token operator">&#61;</span> <span class="token function">htons</span><span class="token punctuation">(</span><span class="token number">9999</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
addr<span class="token punctuation">.</span>sin_addr<span class="token punctuation">.</span>S_un<span class="token punctuation">.</span>S_addr <span class="token operator">&#61;</span> <span class="token function">inet_addr</span><span class="token punctuation">(</span><span class="token string">&#34;127.0.0.1&#34;</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token keyword">int</span> ret <span class="token operator">&#61;</span> <span class="token function">connect</span><span class="token punctuation">(</span>sock<span class="token punctuation">,</span> <span class="token punctuation">(</span>sockaddr<span class="token operator">*</span><span class="token punctuation">)</span><span class="token operator">&amp;</span>addr<span class="token punctuation">,</span> <span class="token keyword">sizeof</span><span class="token punctuation">(</span>addr<span class="token punctuation">)</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token keyword">if</span> <span class="token punctuation">(</span>ret <span class="token operator">&#61;&#61;</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
	cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;连接服务器失败&#34;</span> <span class="token operator">&lt;&lt;</span> endl<span class="token punctuation">;</span>
	<span class="token keyword">return</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>
</code></pre> 
<p>完整代码视图&#xff1a;<br /> <img src="https://img-blog.csdnimg.cn/eb6040c668a042c9ba87e8caa425b26a.png?x-oss-process&#61;image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5L2Z6K-GLQ&#61;&#61;,size_20,color_FFFFFF,t_70,g_se,x_16" alt="在这里插入图片描述" /><br /> 完整代码&#xff1a;</p> 
<pre><code class="prism language-cpp"><span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">define</span> <span class="token macro-name">_WINSOCK_DEPRECATED_NO_WARNINGS</span></span>
<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span><span class="token string">&lt;WinSock2.h&gt;</span></span>
<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span><span class="token string">&lt;iostream&gt;</span></span>
<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">pragma</span> <span class="token expression"><span class="token function">comment</span><span class="token punctuation">(</span>lib<span class="token punctuation">,</span></span><span class="token string">&#34;ws2_32.lib&#34;</span><span class="token expression"><span class="token punctuation">)</span></span></span>
<span class="token keyword">using</span> <span class="token keyword">namespace</span> std<span class="token punctuation">;</span>
<span class="token keyword">int</span> <span class="token function">main</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
	WSADATA data<span class="token punctuation">;</span>
	<span class="token keyword">int</span> ret <span class="token operator">&#61;</span> <span class="token function">WSAStartup</span><span class="token punctuation">(</span><span class="token function">MAKEWORD</span><span class="token punctuation">(</span><span class="token number">2</span><span class="token punctuation">,</span> <span class="token number">2</span><span class="token punctuation">)</span><span class="token punctuation">,</span> <span class="token operator">&amp;</span>data<span class="token punctuation">)</span><span class="token punctuation">;</span>
	<span class="token keyword">if</span> <span class="token punctuation">(</span>ret<span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
		cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;初始化网络错误&#xff01;&#34;</span> <span class="token operator">&lt;&lt;</span> endl<span class="token punctuation">;</span>
		<span class="token function">WSACleanup</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
		<span class="token keyword">return</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>
	<span class="token punctuation">}</span>
	SOCKET sock <span class="token operator">&#61;</span> <span class="token function">socket</span><span class="token punctuation">(</span>AF_INET<span class="token punctuation">,</span> SOCK_STREAM<span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
	sockaddr_in addr<span class="token punctuation">;</span>
	addr<span class="token punctuation">.</span>sin_family <span class="token operator">&#61;</span> AF_INET<span class="token punctuation">;</span>
	addr<span class="token punctuation">.</span>sin_port <span class="token operator">&#61;</span> <span class="token function">htons</span><span class="token punctuation">(</span><span class="token number">9999</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
	addr<span class="token punctuation">.</span>sin_addr<span class="token punctuation">.</span>S_un<span class="token punctuation">.</span>S_addr <span class="token operator">&#61;</span> <span class="token function">inet_addr</span><span class="token punctuation">(</span><span class="token string">&#34;127.0.0.1&#34;</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
	<span class="token keyword">int</span> ret <span class="token operator">&#61;</span> <span class="token function">connect</span><span class="token punctuation">(</span>sock<span class="token punctuation">,</span> <span class="token punctuation">(</span>sockaddr<span class="token operator">*</span><span class="token punctuation">)</span><span class="token operator">&amp;</span>addr<span class="token punctuation">,</span> <span class="token keyword">sizeof</span><span class="token punctuation">(</span>addr<span class="token punctuation">)</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
	<span class="token keyword">if</span> <span class="token punctuation">(</span>ret <span class="token operator">&#61;&#61;</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
		<span class="token function">WSACleanup</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
		cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;连接服务器失败&#34;</span> <span class="token operator">&lt;&lt;</span> endl<span class="token punctuation">;</span>
		<span class="token keyword">return</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>
	<span class="token punctuation">}</span>
	<span class="token keyword">char</span> buf<span class="token punctuation">[</span><span class="token number">0xFF</span><span class="token punctuation">]</span><span class="token punctuation">;</span>
	ret<span class="token operator">&#61;</span><span class="token function">recv</span><span class="token punctuation">(</span>sock<span class="token punctuation">,</span>buf<span class="token punctuation">,</span><span class="token keyword">sizeof</span><span class="token punctuation">(</span>buf<span class="token punctuation">)</span><span class="token punctuation">,</span><span class="token number">0</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
	<span class="token keyword">if</span> <span class="token punctuation">(</span>ret <span class="token operator">&lt;&#61;</span> <span class="token number">0</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
		<span class="token function">WSACleanup</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
		cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;接收服务器数据失败&#34;</span> <span class="token operator">&lt;&lt;</span> endl<span class="token punctuation">;</span>
		<span class="token keyword">return</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>
	<span class="token punctuation">}</span>
	cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;服务器&#xff1a;&#34;</span> <span class="token operator">&lt;&lt;</span> buf <span class="token operator">&lt;&lt;</span> endl<span class="token punctuation">;</span>

	ret<span class="token operator">&#61;</span><span class="token function">send</span><span class="token punctuation">(</span>sock<span class="token punctuation">,</span>buf<span class="token punctuation">,</span>ret<span class="token punctuation">,</span><span class="token number">0</span><span class="token punctuation">)</span><span class="token punctuation">;</span> <span class="token comment">//将接收到的数据发回服务器</span>
	<span class="token keyword">if</span> <span class="token punctuation">(</span>ret <span class="token operator">&lt;&#61;</span> <span class="token number">0</span><span class="token punctuation">)</span> <span class="token punctuation">{<!-- --></span>
		<span class="token function">WSACleanup</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
		cout <span class="token operator">&lt;&lt;</span> <span class="token string">&#34;发送服务器数据失败&#34;</span> <span class="token operator">&lt;&lt;</span> endl<span class="token punctuation">;</span>
		<span class="token keyword">return</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>
	<span class="token punctuation">}</span>
	<span class="token function">WSACleanup</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>

</code></pre> 
<h1><a id="_386"></a>三、其它网络相关函数</h1> 
<h2><a id="htonsntohs_387"></a>htons,ntohs等</h2> 
<p>这种函数名有固定的意义&#xff1a;</p> 
<ul><li>h:home</li><li>n:network</li><li>s:short</li><li>l:long</li></ul> 
<p>htons&#xff1a;意思就是本机字节序转到网络字节序&#xff0c;short类型的长度<br /> ntohs&#xff1a;意思就是网络字节序转到本机字节序&#xff0c;short类型的长度</p> 
<p>还有htonl,htonll,htonf等也是类似的意思</p> 
<h2><a id="inet_addrinet_ntoa_399"></a>inet_addr&#xff0c;inet_ntoa</h2> 
<ul><li>inet_addr:负责将我们平时看到的网络地址127.0.0.1等转化为网络字节序</li><li>inet_ntoa&#xff1a;负责将网络字节序还原为我们平时看到的字符串127.0.0.1等</li></ul> 
<p>使用方法&#xff1a;</p> 
<pre><code class="prism language-cpp">sockaddr_in addr<span class="token punctuation">;</span>
addr<span class="token punctuation">.</span>sin_addr<span class="token punctuation">.</span>S_un<span class="token punctuation">.</span>S_addr <span class="token operator">&#61;</span> <span class="token function">inet_addr</span><span class="token punctuation">(</span><span class="token string">&#34;127.0.0.1&#34;</span><span class="token punctuation">)</span><span class="token punctuation">;</span> <span class="token comment">//将127.0.0.1转换为网络字节序</span>
<span class="token keyword">char</span><span class="token operator">*</span> c_IP <span class="token operator">&#61;</span> <span class="token function">inet_ntoa</span><span class="token punctuation">(</span>addr<span class="token punctuation">.</span>sin_addr<span class="token punctuation">)</span><span class="token punctuation">;</span><span class="token comment">//将网络字节序转换为127.0.0.1字符串</span>
</code></pre> 
<h2><a id="gethostbyname_411"></a>gethostbyname</h2> 
<p>通过域名获取ip地址&#xff0c;比如我们常见的www.baidu.com的ip地址是多少呢&#xff1f;就可以通过这个函数获取</p> 
<p>使用方法&#xff1a;</p> 
<pre><code class="prism language-cpp"><span class="token comment">//获取主机ip</span>
HOSTENT<span class="token operator">*</span> host <span class="token operator">&#61;</span> <span class="token function">gethostbyname</span><span class="token punctuation">(</span><span class="token string">&#34;www.baidu.com&#34;</span><span class="token punctuation">)</span><span class="token punctuation">;</span> <span class="token comment">//如获取网站IP地址&#xff0c;参数填写域名即可&#xff0c;不需加&#34;http://&#34;</span>
<span class="token keyword">if</span> <span class="token punctuation">(</span>host <span class="token operator">&#61;&#61;</span> <span class="token constant">NULL</span><span class="token punctuation">)</span>
<span class="token punctuation">{<!-- --></span>
	<span class="token keyword">return</span> <span class="token boolean">false</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>
<span class="token comment">//转化为char*并拷贝返回</span>
cout <span class="token operator">&lt;&lt;</span> <span class="token function">inet_ntoa</span><span class="token punctuation">(</span><span class="token operator">*</span><span class="token punctuation">(</span>in_addr<span class="token operator">*</span><span class="token punctuation">)</span><span class="token operator">*</span>host<span class="token operator">-&gt;</span>h_addr_list<span class="token punctuation">)</span><span class="token punctuation">;</span>
</code></pre> 
<h2><a id="_426"></a>注意事项</h2> 
<p>这些函数都被微软定为不安全函数&#xff0c;想正常使用就必须在代码最前面定义宏&#xff1a;</p> 
<pre><code class="prism language-cpp"><span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">define</span> <span class="token macro-name">_WINSOCK_DEPRECATED_NO_WARNINGS</span></span>
</code></pre>
                </div>
                <link href="https://csdnimg.cn/release/blogv2/dist/mdeditor/css/editerView/markdown_views-22a2fefd3b.css" rel="stylesheet">
                <link href="https://csdnimg.cn/release/blogv2/dist/mdeditor/css/style-4f8fbf9108.css" rel="stylesheet">
        </div>
        <div id="treeSkill"></div>
        <div id="blogExtensionBox" style="width:400px;margin:auto;margin-top:12px" class="blog-extension-box"></div>
    </article>
  <script>
  $(function() {
    setTimeout(function () {
      var mathcodeList = document.querySelectorAll('.htmledit_views img.mathcode');
      if (mathcodeList.length > 0) {
        var testImg = new Image();
        testImg.onerror = function () {
          mathcodeList.forEach(function (item) {
            $(item).before('<span class="img-codecogs">\\(' + item.alt + '\\)</span>');
            $(item).remove();
          })
          MathJax.Hub.Queue(["Typeset",MathJax.Hub]);
        }
        testImg.src = mathcodeList[0].src;
      }
    }, 1000)
  })
  </script>
</div>
            <div class="hide-article-box hide-article-pos text-center">
                    <a class="btn-readmore fans_read_more btn-readmore-gz" id="btn-readmore-zk">
                        <span class="follow-text">关注博主即可阅读全文</span>
                        <img class="chevrondown" src="https://csdnimg.cn/release/blogv2/dist/pc/img/arrowDownAttend.png">
                    </a>
            </div>
<div class="more-toolbox-new" id="toolBarBox">
    <div class="left-toolbox">
        <div class="toolbox-left">
            <div class="profile-box"><a class="profile-href" target="_blank" href="https://blog.csdn.net/weixin_50964512"><img class="profile-img" src="https://profile.csdnimg.cn/4/4/B/3_weixin_50964512"><span class="profile-name">余识-</span></a></div>
            <div class="profile-attend">
                    <a class="tool-attend tool-bt-button tool-bt-attend" href="javascript:;" data-report-view='{"mod":"1592215036_002","spm":"1001.2101.3001.4232","extend1":"关注"}'>关注</a>
                <a class="tool-item-follow active-animation" style="display:none;">关注</a>
            </div>
        </div>
        <div class="toolbox-middle">
        <ul class="toolbox-list">
            <li class="tool-item tool-item-size tool-active is-like" id="is-like">
            <a class="tool-item-href">
                <img style="display:none;" id="is-like-imgactive-animation-like" class="animation-dom active-animation" src="https://csdnimg.cn/release/blogv2/dist/pc/img/tobarThumbUpactive.png" alt="">
                <img class="isactive" style="display:none" id="is-like-imgactive" src="https://csdnimg.cn/release/blogv2/dist/pc/img/newHeart2021Active.png" alt="">
                <img class="isdefault" style="display:block" id="is-like-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/newHeart2021Black.png" alt="">  
                <span id="spanCount" class="count ">
                        35
                </span>
            </a>
            <div class="tool-hover-tip"><span class="text space">点赞</span></div>
            </li>
            <li class="tool-item tool-item-size tool-active is-unlike" id="is-unlike">
            <a class="tool-item-href">
                <img class="isactive" style="margin-right:0px;display:none" id="is-unlike-imgactive" src="https://csdnimg.cn/release/blogv2/dist/pc/img/newUnHeart2021Active.png" alt="">
                <img class="isdefault" style="margin-right:0px;display:block" id="is-unlike-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/newUnHeart2021Black.png" alt="">
                <span id="unlikeCount" class="count "></span>
            </a>
            <div class="tool-hover-tip"><span class="text space">踩</span></div>
            </li>
            <li class="tool-item tool-item-size tool-active is-collection ">
            <a class="tool-item-href" href="javascript:;" data-report-click='{"mod":"popu_824","spm":"1001.2101.3001.4130","ab":"new"}'>
                <img style="display:none" id="is-collection-img-collection" class="animation-dom active-animation" src="https://csdnimg.cn/release/blogv2/dist/pc/img/tobarCollectionActive.png" alt="">
                <img class="isdefault" id="is-collection-img" style="display:block" src="https://csdnimg.cn/release/blogv2/dist/pc/img/newCollectBlack.png" alt="">
                <img class="isactive" id="is-collection-imgactive" style="display:none" src="https://csdnimg.cn/release/blogv2/dist/pc/img/newCollectActive.png" alt="">
                <span class="count get-collection " id="get-collection">
                    198
                </span>
            </a>
            <div class="tool-hover-tip"><span class="text space">收藏</span></div>
            </li>
            <li class="tool-item tool-item-size tool-active tool-item-reward">
                <a class="tool-item-href" href="javascript:;" data-report-click='{"mod":"popu_830","spm":"1001.2101.3001.4237","dest":"","ab":"new"}'>
                <img class="isdefault reward-bt" id="rewardBtNew" src="https://csdnimg.cn/release/blogv2/dist/pc/img/newRewardBlack.png" alt="打赏">
                <span class="count"></span>
                </a>
                <div class="tool-hover-tip"><span class="text space">打赏</span></div>
            </li>
            <li class="tool-item tool-item-size tool-active tool-item-comment">
            <a class="tool-item-href go-side-comment" data-report-click='{"spm":"1001.2101.3001.7009"}'>
                <img class="isdefault" src="https://csdnimg.cn/release/blogv2/dist/pc/img/newComment2021Black.png" alt="">
                <span class="count">
                    3
                </span>
            </a>
            <div class="tool-hover-tip"><span class="text space">评论</span></div>
            </li>
            <li class="tool-item tool-item-bar">
            </li>
            <li class="tool-item tool-item-size tool-active tool-QRcode" id="tool-share">
                <a class="tool-item-href" href="javascript:;" data-report-click='{"mod":"1582594662_002","spm":"1001.2101.3001.4129","ab":"new"}'>
                    <img class="isdefault" src="https://csdnimg.cn/release/blogv2/dist/pc/img/newShareBlack.png" alt="">
                </a>
                <div class="QRcode" id="tool-QRcode">
                    <div class="share-bg-icon icon1" id="shareBgIcon"></div>
                    <div class="share-bg-box">
                        <div class="share-content">
                            <img class="share-avatar" src="https://profile.csdnimg.cn/4/4/B/3_weixin_50964512" alt="">
                            <div class="share-tit">C/C++网络编程详解（Windows版）</div>
                            <div class="share-dec">简析一个最简单的服务器和客户端怎么写，以及相关网络函数的常用方法</div>
                            <a id="copyPosterUrl" class="url" data-report-click='{"spm":"1001.2101.3001.7493"}' data-report-view='{"spm":"1001.2101.3001.7493"}'>复制链接</a>
                        </div>
                        <div class="share-code">
                            <div class="share-code-box" id='shareCode'></div>
                            <div class="share-code-text">扫一扫</div>
                        </div>
                        
                    </div>
                    <div class="share-code-type">
                      
                    </div>
                </div>
            </li>
        </ul>
        </div>
        <div class="toolbox-right">
                <div class="tool-directory">
                    <a class="bt-columnlist-show"
                    data-id="11648675"
                    data-free="true"
                    data-subscribe="false"
                    data-title="C++基础知识分享"
                    data-img="https://img-blog.csdnimg.cn/20190918140037908.png?x-oss-process=image/resize,m_fixed,h_224,w_224"
                    data-url="https://blog.csdn.net/weixin_50964512/category_11648675.html"
                    data-sum="9"
                    data-people="16"
                    data-price="0"
                    data-oldprice="0"
                    data-join="false"
                    data-studyvip="false"
                    data-studysubscribe="false"
                    data-report-view='{"spm":"1001.2101.3001.6334","extend1":"专栏目录"}'
                    data-report-click='{"spm":"1001.2101.3001.6334","extend1":"专栏目录"}'
                    >专栏目录</a>
                </div>
        </div>
    </div>  
</div>
<script type=text/javascript crossorigin src="https://csdnimg.cn/release/phoenix/production/qrcode-7c90a92189.min.js"></script>
<script src="//g.csdnimg.cn/??sharewx/1.2.1/sharewx.js" type="text/javascript"></script>
<script type="text/javascript" crossorigin src="https://g.csdnimg.cn/common/csdn-login-box/csdn-login-box.js"></script>
<script type="text/javascript" crossorigin src="https://g.csdnimg.cn/collection-box/2.1.0/collection-box.js"></script>
                <div class="first-recommend-box recommend-box ">
<div class="recommend-item-box type_blog clearfix" data-url="https://blog.csdn.net/weixin_42351003/article/details/80519029"  data-report-view='{"ab":"new","spm":"1001.2101.3001.6661.1","mod":"popu_871","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant_t0.none-task-blog-2~default~CTRLIST~Rate-1-80519029-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"1","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/weixin_42351003/article/details/80519029"}'>
	<div class="content-box">
		<div class="content-blog display-flex">
			<div class="title-box">
				<a href="https://blog.csdn.net/weixin_42351003/article/details/80519029" class="tit" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6661.1","mod":"popu_871","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant_t0.none-task-blog-2~default~CTRLIST~Rate-1-80519029-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"1","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/weixin_42351003/article/details/80519029"}'  data-report-query='spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-80519029-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-80519029-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
					<div class="left ellipsis-online ellipsis-online-1">C/<em>C++</em> socket套接字<em>详解</em>（<em>Windows</em>）</div>
				</a>
			</div>
			<div class="info-box display-flex">
				<div class="info">
					<a href="https://blog.csdn.net/weixin_42351003" target="_blank"><span class="blog-title">CRC的博客</span></a>
				</div>
				<div class="info display-flex">
					<span class="info-block time">06-01</span>
					<span class="info-block read"><img class="read-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/readCountWhite.png" alt="">
					1万+
					</span>
				</div>
			</div>
		</div>
		<div class="desc-box">
			<a href="https://blog.csdn.net/weixin_42351003/article/details/80519029" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6661.1","mod":"popu_871","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant_t0.none-task-blog-2~default~CTRLIST~Rate-1-80519029-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"1","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/weixin_42351003/article/details/80519029"}'  data-report-query='spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-80519029-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-80519029-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
				<div class="desc ellipsis-online ellipsis-online-1">一、编译环境本篇博客是在<em>windows</em>系统下的CodeBlocks环境下编写而成的，Linux系统以及其他编译环境暂不适用关于如何CodeBlocks如何安装和配置，可以参考链接（转自萤火虫塔莉）：CodeBlocks的安装以及编译器的配置...</div>
			</a>
		</div>
	</div>
</div>
                </div>
            <script src="https://csdnimg.cn/release/blogv2/dist/components/js/pc_wap_commontools-d5fda285fa.min.js" type="text/javascript" async></script>
            <div class="second-recommend-box recommend-box ">
<div class="recommend-item-box type_course clearfix" data-url="https://edu.csdn.net/course/detail/6082"  data-report-view='{"ab":"new","spm":"1001.2101.3001.6650.1","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-course-2~default~BlogCommendFromBaidu~Paid-1-6082-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"1","strategy":"2~default~BlogCommendFromBaidu~Paid","dest":"https://edu.csdn.net/course/detail/6082"}'>
	<div class="content-box">
		<div class="content-blog display-flex">
			<div class="title-box">
				<a href="https://edu.csdn.net/course/detail/6082" class="tit" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.1","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-course-2~default~BlogCommendFromBaidu~Paid-1-6082-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"1","strategy":"2~default~BlogCommendFromBaidu~Paid","dest":"https://edu.csdn.net/course/detail/6082"}'  data-report-query='spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-course-2%7Edefault%7EBlogCommendFromBaidu%7EPaid-1-6082-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-course-2%7Edefault%7EBlogCommendFromBaidu%7EPaid-1-6082-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
					<div class="left ellipsis-online ellipsis-online-1"><em>C++</em><em>网络编程</em>进阶</div>
				</a>
			</div>
			<div class="info-box display-flex">
				<div class="info display-flex">
					<span class="info-block">09-20</span>
				</div>
			</div>
		</div>
		<div class="desc-box">
			<a href="https://edu.csdn.net/course/detail/6082" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.1","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-course-2~default~BlogCommendFromBaidu~Paid-1-6082-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"1","strategy":"2~default~BlogCommendFromBaidu~Paid","dest":"https://edu.csdn.net/course/detail/6082"}'  data-report-query='spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-course-2%7Edefault%7EBlogCommendFromBaidu%7EPaid-1-6082-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-course-2%7Edefault%7EBlogCommendFromBaidu%7EPaid-1-6082-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
				<div class="desc ellipsis-online ellipsis-online-1">C/S模型在企业级的软件开发中非常常见，高并发<em>网络</em>通讯更是很多项目的核心模块，学好socket <em>网络编程</em>显得尤为重要，本课程分为TCP/IP 协议、socket基础与进阶的异步通讯模型三个部分，通过浅显易懂的代码与讲解，让你的<em>C++</em><em>网络编程</em>能力得到质的飞跃，具备开发高并发服务器的能力!</div>
			</a>
		</div>
	</div>
</div>
            </div>
<a id="commentBox" name="commentBox"></a>
<div id="pcCommentBox" class="comment-box comment-box-new2  login-comment-box-new" style="display:block">
		<div class="has-comment" style="display:block">
		<div class="has-comment-tit">评论<span class="count go-side-comment">3</span><span class="text go-side-comment">条</span><img class="go-side-comment more" src="https://csdnimg.cn/release/blogv2/dist/pc/img/commentArrowRightWhite.png" alt=""><a class="has-comment-bt-right go-side-comment focus">写评论</a></div>
			<div class="has-comment-con comment-operate-item"></div>
		</div>
		<div class="unhas-comment" style="display:none">
			<div class="unhas-comment-left">评论</div>
			<div class="unhas-comment-right"><a class="go-side-comment focus">写评论</a></div>
		</div>
</div>
            <div class="recommend-box insert-baidu-box recommend-box-style ">
                <div class="recommend-item-box no-index" style="display:none"></div>
<div class="recommend-item-box type_blog clearfix" data-url="https://blog.csdn.net/qq_35227495/article/details/125942709"  data-report-view='{"ab":"new","spm":"1001.2101.3001.6650.2","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-2-125942709-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"2","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/qq_35227495/article/details/125942709"}'>
	<div class="content-box">
		<div class="content-blog display-flex">
			<div class="title-box">
				<a href="https://blog.csdn.net/qq_35227495/article/details/125942709" class="tit" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.2","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-2-125942709-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"2","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/qq_35227495/article/details/125942709"}'  data-report-query='spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-2-125942709-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-2-125942709-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
					<div class="left ellipsis-online ellipsis-online-1"><em>C++</em> <em>网络编程</em>（第二篇）</div>
				</a>
			</div>
			<div class="info-box display-flex">
				<div class="info">
					<a href="https://blog.csdn.net/qq_35227495" target="_blank"><span class="blog-title">qq_35227495的博客</span></a>
				</div>
				<div class="info display-flex">
					<span class="info-block time">07-23</span>
					<span class="info-block read"><img class="read-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/readCountWhite.png" alt="">
					865
					</span>
				</div>
			</div>
		</div>
		<div class="desc-box">
			<a href="https://blog.csdn.net/qq_35227495/article/details/125942709" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.2","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-2-125942709-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"2","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/qq_35227495/article/details/125942709"}'  data-report-query='spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-2-125942709-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-2-125942709-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
				<div class="desc ellipsis-online ellipsis-online-1"><em>网络</em>通信的模型和协议</div>
			</a>
		</div>
	</div>
</div>
<div class="recommend-item-box type_blog clearfix" data-url="https://blog.csdn.net/weixin_45266730/article/details/127264932"  data-report-view='{"ab":"new","spm":"1001.2101.3001.6650.3","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~YuanLiJiHua~Position-3-127264932-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"3","strategy":"2~default~YuanLiJiHua~Position","dest":"https://blog.csdn.net/weixin_45266730/article/details/127264932"}'>
	<div class="content-box">
		<div class="content-blog display-flex">
			<div class="title-box">
				<a href="https://blog.csdn.net/weixin_45266730/article/details/127264932" class="tit" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.3","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~YuanLiJiHua~Position-3-127264932-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"3","strategy":"2~default~YuanLiJiHua~Position","dest":"https://blog.csdn.net/weixin_45266730/article/details/127264932"}'  data-report-query='spm=1001.2101.3001.6650.3&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EYuanLiJiHua%7EPosition-3-127264932-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EYuanLiJiHua%7EPosition-3-127264932-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
					<div class="left ellipsis-online ellipsis-online-1">Socket：套接字<em>网络编程</em>（<em>C++</em>）</div>
					<div class="tag">最新发布</div>
				</a>
			</div>
			<div class="info-box display-flex">
				<div class="info">
					<a href="https://blog.csdn.net/weixin_45266730" target="_blank"><span class="blog-title">weixin_45266730的博客</span></a>
				</div>
				<div class="info display-flex">
					<span class="info-block time">10-11</span>
					<span class="info-block read"><img class="read-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/readCountWhite.png" alt="">
					598
					</span>
				</div>
			</div>
		</div>
		<div class="desc-box">
			<a href="https://blog.csdn.net/weixin_45266730/article/details/127264932" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.3","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~YuanLiJiHua~Position-3-127264932-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"3","strategy":"2~default~YuanLiJiHua~Position","dest":"https://blog.csdn.net/weixin_45266730/article/details/127264932"}'  data-report-query='spm=1001.2101.3001.6650.3&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EYuanLiJiHua%7EPosition-3-127264932-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EYuanLiJiHua%7EPosition-3-127264932-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
				<div class="desc ellipsis-online ellipsis-online-1">Socket：套接字<em>网络编程</em>（<em>C++</em>）</div>
			</a>
		</div>
	</div>
</div>
		<dl id="recommend-item-box-tow" class="recommend-item-box type_blog clearfix">
			
		</dl>
<div class="recommend-item-box type_blog clearfix" data-url="https://blog.csdn.net/no1xium/article/details/126684753"  data-report-view='{"ab":"new","spm":"1001.2101.3001.6650.4","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-4-126684753-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"4","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/no1xium/article/details/126684753"}'>
	<div class="content-box">
		<div class="content-blog display-flex">
			<div class="title-box">
				<a href="https://blog.csdn.net/no1xium/article/details/126684753" class="tit" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.4","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-4-126684753-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"4","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/no1xium/article/details/126684753"}'  data-report-query='spm=1001.2101.3001.6650.4&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-4-126684753-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-4-126684753-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
					<div class="left ellipsis-online ellipsis-online-1"><em>Windows</em> 配置 C/<em>C++</em> 编译环境指南</div>
				</a>
			</div>
			<div class="info-box display-flex">
				<div class="info">
					<a href="https://blog.csdn.net/no1xium" target="_blank"><span class="blog-title">Linux I Tell U</span></a>
				</div>
				<div class="info display-flex">
					<span class="info-block time">09-05</span>
					<span class="info-block read"><img class="read-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/readCountWhite.png" alt="">
					1042
					</span>
				</div>
			</div>
		</div>
		<div class="desc-box">
			<a href="https://blog.csdn.net/no1xium/article/details/126684753" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.4","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-4-126684753-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"4","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/no1xium/article/details/126684753"}'  data-report-query='spm=1001.2101.3001.6650.4&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-4-126684753-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-4-126684753-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
				<div class="desc ellipsis-online ellipsis-online-1">gcc是c/<em>c++</em>的编译器，通常只能在 Linux 上才能用。如果我们要在<em>windows</em>上使用它，那么我们需要用MinGW来构建环境。</div>
			</a>
		</div>
	</div>
</div>
<div class="recommend-item-box type_blog clearfix" data-url="https://blog.csdn.net/qq_45724328/article/details/120668822"  data-report-view='{"ab":"new","spm":"1001.2101.3001.6650.5","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-5-120668822-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"5","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/qq_45724328/article/details/120668822"}'>
	<div class="content-box">
		<div class="content-blog display-flex">
			<div class="title-box">
				<a href="https://blog.csdn.net/qq_45724328/article/details/120668822" class="tit" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.5","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-5-120668822-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"5","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/qq_45724328/article/details/120668822"}'  data-report-query='spm=1001.2101.3001.6650.5&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-5-120668822-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-5-120668822-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
					<div class="left ellipsis-online ellipsis-online-1"><em>c++</em>的<em>网络编程</em>TCP</div>
				</a>
			</div>
			<div class="info-box display-flex">
				<div class="info">
					<a href="https://blog.csdn.net/qq_45724328" target="_blank"><span class="blog-title">qq_45724328的博客</span></a>
				</div>
				<div class="info display-flex">
					<span class="info-block time">10-09</span>
					<span class="info-block read"><img class="read-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/readCountWhite.png" alt="">
					749
					</span>
				</div>
			</div>
		</div>
		<div class="desc-box">
			<a href="https://blog.csdn.net/qq_45724328/article/details/120668822" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.5","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-5-120668822-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"5","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/qq_45724328/article/details/120668822"}'  data-report-query='spm=1001.2101.3001.6650.5&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-5-120668822-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-5-120668822-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
				<div class="desc ellipsis-online ellipsis-online-1"><em>c++</em>的<em>网络编程</em>TCP
服务器端
// <em>c++</em><em>网络编程</em>.cpp : 此文件包含 &quot;main&quot; 函数。程序执行将在此处开始并结束。
//

#include &lt;iostream&gt;
#include&lt;WinSock2.h&gt;
//#include&lt;winsock.h&gt;
//#include&lt;winsock.h&gt;

#pragma comment(lib ,&quot;ws2_32.lib&quot;)

int main()
{
    //加载套接字库
    WORD wVersi</div>
			</a>
		</div>
	</div>
</div>
<div class="recommend-item-box type_blog clearfix" data-url="https://blog.csdn.net/weixin_41316331/article/details/88770910"  data-report-view='{"ab":"new","spm":"1001.2101.3001.6650.6","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-6-88770910-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"6","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/weixin_41316331/article/details/88770910"}'>
	<div class="content-box">
		<div class="content-blog display-flex">
			<div class="title-box">
				<a href="https://blog.csdn.net/weixin_41316331/article/details/88770910" class="tit" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.6","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-6-88770910-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"6","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/weixin_41316331/article/details/88770910"}'  data-report-query='spm=1001.2101.3001.6650.6&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-6-88770910-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-6-88770910-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
					<div class="left ellipsis-online ellipsis-online-1"><em>C++</em><em>网络编程</em>（实例）</div>
				</a>
			</div>
			<div class="info-box display-flex">
				<div class="info">
					<a href="https://blog.csdn.net/weixin_41316331" target="_blank"><span class="blog-title">weixin_41316331的博客</span></a>
				</div>
				<div class="info display-flex">
					<span class="info-block time">03-23</span>
					<span class="info-block read"><img class="read-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/readCountWhite.png" alt="">
					5072
					</span>
				</div>
			</div>
		</div>
		<div class="desc-box">
			<a href="https://blog.csdn.net/weixin_41316331/article/details/88770910" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.6","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-6-88770910-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"6","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/weixin_41316331/article/details/88770910"}'  data-report-query='spm=1001.2101.3001.6650.6&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-6-88770910-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-6-88770910-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
				<div class="desc ellipsis-online ellipsis-online-1">服务端
#include &lt;sys/types.h&gt;
#include &lt;sys/socket.h&gt;
#include&lt;netinet/in.h&gt;
#include&lt;iostream&gt;
#include &lt;unistd.h&gt;
#include &lt;cstring&gt;
using namespace std;

int main()...</div>
			</a>
		</div>
	</div>
</div>
<div class="recommend-item-box type_blog clearfix" data-url="https://blog.csdn.net/qq_43316970/article/details/124331142"  data-report-view='{"ab":"new","spm":"1001.2101.3001.6650.7","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-7-124331142-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"7","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://blog.csdn.net/qq_43316970/article/details/124331142"}'>
	<div class="content-box">
		<div class="content-blog display-flex">
			<div class="title-box">
				<a href="https://blog.csdn.net/qq_43316970/article/details/124331142" class="tit" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.7","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-7-124331142-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"7","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://blog.csdn.net/qq_43316970/article/details/124331142"}'  data-report-query='spm=1001.2101.3001.6650.7&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-7-124331142-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-7-124331142-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
					<div class="left ellipsis-online ellipsis-online-1"><em>C++</em><em>网络编程</em></div>
				</a>
			</div>
			<div class="info-box display-flex">
				<div class="info">
					<a href="https://blog.csdn.net/qq_43316970" target="_blank"><span class="blog-title">qq_43316970的博客</span></a>
				</div>
				<div class="info display-flex">
					<span class="info-block time">04-23</span>
					<span class="info-block read"><img class="read-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/readCountWhite.png" alt="">
					8119
					</span>
				</div>
			</div>
		</div>
		<div class="desc-box">
			<a href="https://blog.csdn.net/qq_43316970/article/details/124331142" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.7","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-7-124331142-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"7","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://blog.csdn.net/qq_43316970/article/details/124331142"}'  data-report-query='spm=1001.2101.3001.6650.7&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-7-124331142-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-7-124331142-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
				<div class="desc ellipsis-online ellipsis-online-1"><em>网络</em>通信socket
计算机是通过TCP/IP协议进行互联从而进行通信的，为了把复杂的TCP/IP协议隐藏起来，更方便的实现计算机中两个程序进行通信，引出了socket这个概念。

socket翻译为套接字，可以理解为IP地址与端口号的组合。
socket提供了流（stream）和数据报（datagram）两种通信机制，即流socket(SOCK_STREAM)和数据报socket(SOCK_DGRAM)。
流socket基于TCP协议，是一个有序、可靠、双向字节流的通道，传输数据不会丢失、不会重复、顺序也</div>
			</a>
		</div>
	</div>
</div>
<div class="recommend-item-box type_blog clearfix" data-url="https://blog.csdn.net/baidu_16370559/article/details/104646624"  data-report-view='{"ab":"new","spm":"1001.2101.3001.6650.8","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-8-104646624-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"8","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://blog.csdn.net/baidu_16370559/article/details/104646624"}'>
	<div class="content-box">
		<div class="content-blog display-flex">
			<div class="title-box">
				<a href="https://blog.csdn.net/baidu_16370559/article/details/104646624" class="tit" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.8","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-8-104646624-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"8","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://blog.csdn.net/baidu_16370559/article/details/104646624"}'  data-report-query='spm=1001.2101.3001.6650.8&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-8-104646624-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-8-104646624-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
					<div class="left ellipsis-online ellipsis-online-1"><em>windows</em> <em>网络编程</em>大汇总</div>
				</a>
			</div>
			<div class="info-box display-flex">
				<div class="info">
					<a href="https://blog.csdn.net/baidu_16370559" target="_blank"><span class="blog-title">baidu_16370559的博客</span></a>
				</div>
				<div class="info display-flex">
					<span class="info-block time">03-10</span>
					<span class="info-block read"><img class="read-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/readCountWhite.png" alt="">
					2549
					</span>
				</div>
			</div>
		</div>
		<div class="desc-box">
			<a href="https://blog.csdn.net/baidu_16370559/article/details/104646624" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.8","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-8-104646624-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"8","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://blog.csdn.net/baidu_16370559/article/details/104646624"}'  data-report-query='spm=1001.2101.3001.6650.8&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-8-104646624-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-8-104646624-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
				<div class="desc ellipsis-online ellipsis-online-1">使用winsock.h 文件 ，他是个接口，而不是协议，应用在tcp/ip协议中。

流程

WSAStartup函数用于加载 winsock dll <em>版</em>本。一般使用 2.2 就可以了。

WSACleanup函数用于释放资源。
...</div>
			</a>
		</div>
	</div>
</div>
<div class="recommend-item-box type_blog clearfix" data-url="https://blog.csdn.net/weixin_42579072/article/details/103163145"  data-report-view='{"ab":"new","spm":"1001.2101.3001.6650.9","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-9-103163145-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"9","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/weixin_42579072/article/details/103163145"}'>
	<div class="content-box">
		<div class="content-blog display-flex">
			<div class="title-box">
				<a href="https://blog.csdn.net/weixin_42579072/article/details/103163145" class="tit" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.9","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-9-103163145-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"9","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/weixin_42579072/article/details/103163145"}'  data-report-query='spm=1001.2101.3001.6650.9&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-9-103163145-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-9-103163145-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
					<div class="left ellipsis-online ellipsis-online-1"><em>c++</em>之<em>网络编程</em></div>
				</a>
			</div>
			<div class="info-box display-flex">
				<div class="info">
					<a href="https://blog.csdn.net/weixin_42579072" target="_blank"><span class="blog-title">weixin_42579072的博客</span></a>
				</div>
				<div class="info display-flex">
					<span class="info-block time">11-20</span>
					<span class="info-block read"><img class="read-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/readCountWhite.png" alt="">
					3274
					</span>
				</div>
			</div>
		</div>
		<div class="desc-box">
			<a href="https://blog.csdn.net/weixin_42579072/article/details/103163145" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.9","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-9-103163145-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"9","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/weixin_42579072/article/details/103163145"}'  data-report-query='spm=1001.2101.3001.6650.9&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-9-103163145-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-9-103163145-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
				<div class="desc ellipsis-online ellipsis-online-1">TCP和UDP属于传输层协议。其中TCP提供IP环境下的数据可靠传输，它事先为要发送的数据开辟好连接通道（三次握手），然后再进行数据发送；而UDP则不为IP提供可靠性，一般用于实时的视频流传输，像rtp、rtsp就是建立在udp的基础上的。
本文参考基于TCP/IP的<em>网络编程</em>（<em>C++</em>语言编程）

注意关闭安全开发生命周期（SDL）。

基于TCP
基本思路：

服务端：
1、加载socket库（W...</div>
			</a>
		</div>
	</div>
</div>
<div class="recommend-item-box type_blog clearfix" data-url="https://blog.csdn.net/fuyouzhiyi/article/details/120828415"  data-report-view='{"ab":"new","spm":"1001.2101.3001.6650.10","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-10-120828415-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"10","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/fuyouzhiyi/article/details/120828415"}'>
	<div class="content-box">
		<div class="content-blog display-flex">
			<div class="title-box">
				<a href="https://blog.csdn.net/fuyouzhiyi/article/details/120828415" class="tit" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.10","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-10-120828415-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"10","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/fuyouzhiyi/article/details/120828415"}'  data-report-query='spm=1001.2101.3001.6650.10&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-10-120828415-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-10-120828415-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
					<div class="left ellipsis-online ellipsis-online-1"><em>C++</em><em>网络编程</em> 零基础教程</div>
				</a>
			</div>
			<div class="info-box display-flex">
				<div class="info">
					<a href="https://blog.csdn.net/fuyouzhiyi" target="_blank"><span class="blog-title">fuyouzhiyi的博客</span></a>
				</div>
				<div class="info display-flex">
					<span class="info-block time">10-18</span>
					<span class="info-block read"><img class="read-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/readCountWhite.png" alt="">
					1626
					</span>
				</div>
			</div>
		</div>
		<div class="desc-box">
			<a href="https://blog.csdn.net/fuyouzhiyi/article/details/120828415" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.10","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-10-120828415-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"10","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/fuyouzhiyi/article/details/120828415"}'  data-report-query='spm=1001.2101.3001.6650.10&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-10-120828415-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-10-120828415-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
				<div class="desc ellipsis-online ellipsis-online-1"><em>C++</em><em>网络编程</em> 零基础教程demo步骤框架一 服务端二、客户端伪代码<em>详解</em>0 套接字1  <em>Windows</em> 套接字下设置绑定端口监听接受连接请求收发数据关闭SOCKET客服端连接
demo
首先一个可以运行的例子：
<em>windows</em>环境下用<em>c++</em>实现socket编程
步骤
框架
一 服务端
1、加载套接字库，创建套接字（WSAStartup()/socket()）;
2、绑定套接字到一个IP地址和一个端口上（bind()）;
3、将套接字设置为监听模式等待连接请求（listen()）；
4、请求到来后，接受连接请</div>
			</a>
		</div>
	</div>
</div>
<div class="recommend-item-box type_blog clearfix" data-url="https://blog.csdn.net/qq_48243698/article/details/123510416"  data-report-view='{"ab":"new","spm":"1001.2101.3001.6650.11","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-11-123510416-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"11","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/qq_48243698/article/details/123510416"}'>
	<div class="content-box">
		<div class="content-blog display-flex">
			<div class="title-box">
				<a href="https://blog.csdn.net/qq_48243698/article/details/123510416" class="tit" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.11","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-11-123510416-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"11","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/qq_48243698/article/details/123510416"}'  data-report-query='spm=1001.2101.3001.6650.11&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-11-123510416-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-11-123510416-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
					<div class="left ellipsis-online ellipsis-online-1"><em>c++</em><em>网络编程</em>基础知识总结</div>
				</a>
			</div>
			<div class="info-box display-flex">
				<div class="info">
					<a href="https://blog.csdn.net/qq_48243698" target="_blank"><span class="blog-title">qq_48243698的博客</span></a>
				</div>
				<div class="info display-flex">
					<span class="info-block time">03-15</span>
					<span class="info-block read"><img class="read-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/readCountWhite.png" alt="">
					676
					</span>
				</div>
			</div>
		</div>
		<div class="desc-box">
			<a href="https://blog.csdn.net/qq_48243698/article/details/123510416" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.11","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-11-123510416-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"11","strategy":"2~default~CTRLIST~Rate","dest":"https://blog.csdn.net/qq_48243698/article/details/123510416"}'  data-report-query='spm=1001.2101.3001.6650.11&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-11-123510416-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-11-123510416-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
				<div class="desc ellipsis-online ellipsis-online-1">TCP/IP<em>网络</em>通信的API（应用程序接口）。称为Socket接口（套接字）。SOCKET接口是TCP/IP<em>网络</em>最为通用的API。

SOCKET实际在计算机中提供了一个通信端口，可以通过这个端口与任何一个具有SOCKET接口的计算机通信。

应用程序在<em>网络</em>上传输，接收的信息都通过这个SOCKET接口来实现。

Socket可以支持数据的发送和接收

它定义一种称为套接字的变量，发送数据时首先创建套接字，然后使用该套接字的sendto等方法对准某个IP/端口进行数据发送

接收端也首先创建套接字，然后将该套</div>
			</a>
		</div>
	</div>
</div>
<div class="recommend-item-box type_blog clearfix" data-url="https://blog.csdn.net/mao19931004/article/details/47003423"  data-report-view='{"ab":"new","spm":"1001.2101.3001.6650.12","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-12-47003423-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"12","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://blog.csdn.net/mao19931004/article/details/47003423"}'>
	<div class="content-box">
		<div class="content-blog display-flex">
			<div class="title-box">
				<a href="https://blog.csdn.net/mao19931004/article/details/47003423" class="tit" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.12","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-12-47003423-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"12","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://blog.csdn.net/mao19931004/article/details/47003423"}'  data-report-query='spm=1001.2101.3001.6650.12&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-12-47003423-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-12-47003423-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
					<div class="left ellipsis-online ellipsis-online-1"><em>windows</em>编程--<em>网络编程</em>学习--winsock编程(2)</div>
				</a>
			</div>
			<div class="info-box display-flex">
				<div class="info">
					<a href="https://blog.csdn.net/mao19931004" target="_blank"><span class="blog-title">我只是一个单纯的2的博客</span></a>
				</div>
				<div class="info display-flex">
					<span class="info-block time">07-22</span>
					<span class="info-block read"><img class="read-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/readCountWhite.png" alt="">
					1万+
					</span>
				</div>
			</div>
		</div>
		<div class="desc-box">
			<a href="https://blog.csdn.net/mao19931004/article/details/47003423" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.12","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-12-47003423-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"12","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://blog.csdn.net/mao19931004/article/details/47003423"}'  data-report-query='spm=1001.2101.3001.6650.12&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-12-47003423-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-12-47003423-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
				<div class="desc ellipsis-online ellipsis-online-1">Winsock下TCP实现过程</div>
			</a>
		</div>
	</div>
</div>
<div class="recommend-item-box type_blog clearfix" data-url="https://blog.csdn.net/notbaron/article/details/53193185"  data-report-view='{"ab":"new","spm":"1001.2101.3001.6650.13","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-13-53193185-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"13","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://blog.csdn.net/notbaron/article/details/53193185"}'>
	<div class="content-box">
		<div class="content-blog display-flex">
			<div class="title-box">
				<a href="https://blog.csdn.net/notbaron/article/details/53193185" class="tit" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.13","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-13-53193185-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"13","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://blog.csdn.net/notbaron/article/details/53193185"}'  data-report-query='spm=1001.2101.3001.6650.13&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-13-53193185-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-13-53193185-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
					<div class="left ellipsis-online ellipsis-online-1"><em>Windows</em><em>网络编程</em></div>
					<div class="tag">热门推荐</div>
				</a>
			</div>
			<div class="info-box display-flex">
				<div class="info">
					<a href="https://blog.csdn.net/notbaron" target="_blank"><span class="blog-title">badman250的专栏</span></a>
				</div>
				<div class="info display-flex">
					<span class="info-block time">11-16</span>
					<span class="info-block read"><img class="read-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/readCountWhite.png" alt="">
					3万+
					</span>
				</div>
			</div>
		</div>
		<div class="desc-box">
			<a href="https://blog.csdn.net/notbaron/article/details/53193185" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.13","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-13-53193185-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"13","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://blog.csdn.net/notbaron/article/details/53193185"}'  data-report-query='spm=1001.2101.3001.6650.13&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-13-53193185-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-13-53193185-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
				<div class="desc ellipsis-online ellipsis-online-1"><em>Windows</em><em>网络编程</em>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;<em>Windows</em>下<em>网络编程</em>的规范－<em>Windows</em>Sockets是<em>Windows</em>下得到广泛应用的、开放的、支持多种协议的<em>网络编程</em>接口。从1991年的1.0<em>版</em>到1995年的2.0.8<em>版</em>，经过不断完善并在Intel、Microsoft、Sun、SGI、Informix、Novell等公司的全力支持下，已成为<em>Windows</em><em>网络编程</em>的事实上的标准。
相关函数
W</div>
			</a>
		</div>
	</div>
</div>
<div class="recommend-item-box type_blog clearfix" data-url="https://blog.csdn.net/wteruiycbqqvwt/article/details/90404039"  data-report-view='{"ab":"new","spm":"1001.2101.3001.6650.14","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-14-90404039-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"14","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://blog.csdn.net/wteruiycbqqvwt/article/details/90404039"}'>
	<div class="content-box">
		<div class="content-blog display-flex">
			<div class="title-box">
				<a href="https://blog.csdn.net/wteruiycbqqvwt/article/details/90404039" class="tit" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.14","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-14-90404039-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"14","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://blog.csdn.net/wteruiycbqqvwt/article/details/90404039"}'  data-report-query='spm=1001.2101.3001.6650.14&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-14-90404039-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-14-90404039-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
					<div class="left ellipsis-online ellipsis-online-1">socket<em>网络编程</em>示例<em>C++</em>&mdash;&mdash;即时通信系统</div>
				</a>
			</div>
			<div class="info-box display-flex">
				<div class="info">
					<a href="https://blog.csdn.net/wteruiycbqqvwt" target="_blank"><span class="blog-title">$好记性还是要多记录$</span></a>
				</div>
				<div class="info display-flex">
					<span class="info-block time">05-21</span>
					<span class="info-block read"><img class="read-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/readCountWhite.png" alt="">
					498
					</span>
				</div>
			</div>
		</div>
		<div class="desc-box">
			<a href="https://blog.csdn.net/wteruiycbqqvwt/article/details/90404039" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.14","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-14-90404039-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"14","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://blog.csdn.net/wteruiycbqqvwt/article/details/90404039"}'  data-report-query='spm=1001.2101.3001.6650.14&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-14-90404039-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-14-90404039-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
				<div class="desc ellipsis-online ellipsis-online-1">一：项目内容

本项目使用<em>C++</em>实现一个具备服务器端和客户端即时通信且具有私聊功能的聊天室。

目的是学习<em>C++</em><em>网络</em>开发的基本概念，同时也可以熟悉下Linux下的<em>C++</em>程序编译和简单MakeFile编写

二：需求分析

这个聊天室主要有两个程序：

1.服务端：能够接受新的客户连接，并将每个客户端发来的信息，广播给对应的目标客户端。

2.客户端：能够连接服务器，并向服务器发送消息，同时可以接收...</div>
			</a>
		</div>
	</div>
</div>
<div class="recommend-item-box type_blog clearfix" data-url="https://mingshiqiang.blog.csdn.net/article/details/91400832"  data-report-view='{"ab":"new","spm":"1001.2101.3001.6650.15","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-15-91400832-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"15","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://mingshiqiang.blog.csdn.net/article/details/91400832"}'>
	<div class="content-box">
		<div class="content-blog display-flex">
			<div class="title-box">
				<a href="https://mingshiqiang.blog.csdn.net/article/details/91400832" class="tit" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.15","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-15-91400832-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"15","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://mingshiqiang.blog.csdn.net/article/details/91400832"}'  data-report-query='spm=1001.2101.3001.6650.15&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-15-91400832-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-15-91400832-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
					<div class="left ellipsis-online ellipsis-online-1"><em>windows</em> <em>C++</em> <em>网络编程</em></div>
				</a>
			</div>
			<div class="info-box display-flex">
				<div class="info">
					<a href="https://blog.csdn.net/yao_hou" target="_blank"><span class="blog-title">C++/Qt/音视频/RTC</span></a>
				</div>
				<div class="info display-flex">
					<span class="info-block time">06-10</span>
					<span class="info-block read"><img class="read-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/readCountWhite.png" alt="">
					1万+
					</span>
				</div>
			</div>
		</div>
		<div class="desc-box">
			<a href="https://mingshiqiang.blog.csdn.net/article/details/91400832" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.15","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-15-91400832-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"15","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://mingshiqiang.blog.csdn.net/article/details/91400832"}'  data-report-query='spm=1001.2101.3001.6650.15&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-15-91400832-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-15-91400832-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
				<div class="desc ellipsis-online ellipsis-online-1">一、什么是Socket

 socket即套接字，用于描述地址和端口，是一个通信链的句柄。应用程序通过socket向<em>网络</em>发出请求或者回应。

 sockets(套接字)编程有三种，流式套接字（SOCK_STREAM），数据报套接字（SOCK_DGRAM），原始套接字（SOCK_RAW）；前两种较常用。基于TCP的socket编程是采用的流式套接字。

  ...</div>
			</a>
		</div>
	</div>
</div>
<div class="recommend-item-box type_blog clearfix" data-url="https://blog.csdn.net/weixin_30599769/article/details/97281099"  data-report-view='{"ab":"new","spm":"1001.2101.3001.6650.16","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-16-97281099-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"16","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://blog.csdn.net/weixin_30599769/article/details/97281099"}'>
	<div class="content-box">
		<div class="content-blog display-flex">
			<div class="title-box">
				<a href="https://blog.csdn.net/weixin_30599769/article/details/97281099" class="tit" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.16","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-16-97281099-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"16","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://blog.csdn.net/weixin_30599769/article/details/97281099"}'  data-report-query='spm=1001.2101.3001.6650.16&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-16-97281099-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-16-97281099-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
					<div class="left ellipsis-online ellipsis-online-1">Socket简介</div>
				</a>
			</div>
			<div class="info-box display-flex">
				<div class="info">
					<a href="https://blog.csdn.net/weixin_30599769" target="_blank"><span class="blog-title">weixin_30599769的博客</span></a>
				</div>
				<div class="info display-flex">
					<span class="info-block time">06-08</span>
					<span class="info-block read"><img class="read-img" src="https://csdnimg.cn/release/blogv2/dist/pc/img/readCountWhite.png" alt="">
					233
					</span>
				</div>
			</div>
		</div>
		<div class="desc-box">
			<a href="https://blog.csdn.net/weixin_30599769/article/details/97281099" target="_blank"  data-report-click='{"ab":"new","spm":"1001.2101.3001.6650.16","mod":"popu_387","extra":"{\"highlightScore\":0.0,\"utm_medium\":\"distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-16-97281099-blog-123743421.pc_relevant_multi_platform_whitelistv3\",\"dist_request_id\":\"1669772314901_13200\"}","dist_request_id":"1669772314901_13200","ab_strategy":"featuressortv3","index":"16","strategy":"2~default~BlogCommendFromBaidu~Rate","dest":"https://blog.csdn.net/weixin_30599769/article/details/97281099"}'  data-report-query='spm=1001.2101.3001.6650.16&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-16-97281099-blog-123743421.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-16-97281099-blog-123743421.pc_relevant_multi_platform_whitelistv3'>
				<div class="desc ellipsis-online ellipsis-online-1">本文全部摘抄http://c.biancheng.net/cpp/html/3029.html
大多数项目是在Linux下开发服务器端，而在<em>Windows</em>下开发客户端，需要经常在两大平台之间进行切换，单独学习一种平台没有实践意义。两大平台下的 socket 编程非常相似。
在计算机通信领域，socket 被翻译为&ldquo;套接字&rdquo;，它是计算机之间进行通信的一种约定或一种方式。通过 socket 这种约...</div>
			</a>
		</div>
	</div>
</div>
            </div>
<div id="recommendNps" class="recommend-nps-box common-nps-box">
  <h3 class="aside-title">“相关推荐”对你有帮助么？</h3>
  <div class="aside-content">
      <ul class="newnps-list">
          <li class="newnps-item" data-type="非常没帮助">
              <div class="newnps-img-box">
                  <img class="newnps-img active" src="https://csdnimg.cn/release/blogv2/dist/pc/img/npsFeel1.png" alt="">
                  <img class="newnps-img default" src="https://csdnimg.cn/release/blogv2/dist/pc/img/npsFeelGrey1.png" alt="">
              </div>
              <div class="newnps-text">非常没帮助</div>
          </li>
          <li class="newnps-item" data-type="没帮助">
              <div class="newnps-img-box">
                  <img class="newnps-img active" src="https://csdnimg.cn/release/blogv2/dist/pc/img/npsFeel2.png" alt="">
                  <img class="newnps-img default" src="https://csdnimg.cn/release/blogv2/dist/pc/img/npsFeelGrey2.png" alt="">
              </div>
              <div class="newnps-text">没帮助</div>
          </li>
          <li class="newnps-item" data-type="一般">
              <div class="newnps-img-box">
                  <img class="newnps-img active" src="https://csdnimg.cn/release/blogv2/dist/pc/img/npsFeel3.png" alt="">
                  <img class="newnps-img default" src="https://csdnimg.cn/release/blogv2/dist/pc/img/npsFeelGrey3.png" alt="">
              </div>
              <div class="newnps-text">一般</div>
          </li>
          <li class="newnps-item" data-type="有帮助">
              <div class="newnps-img-box">
                  <img class="newnps-img active" src="https://csdnimg.cn/release/blogv2/dist/pc/img/npsFeel4.png" alt="">
                  <img class="newnps-img default" src="https://csdnimg.cn/release/blogv2/dist/pc/img/npsFeelGrey4.png" alt="">
              </div>
              <div class="newnps-text">有帮助</div>
          </li>
          <li class="newnps-item" data-type="非常有帮助">
              <div class="newnps-img-box">
                  <img class="newnps-img active" src="https://csdnimg.cn/release/blogv2/dist/pc/img/npsFeel5.png" alt="">
                  <img class="newnps-img default" src="https://csdnimg.cn/release/blogv2/dist/pc/img/npsFeelGrey5.png" alt="">
              </div>
              <div class="newnps-text">非常有帮助</div>
          </li>
      </ul>
      <div class="newnps-form-box">
      <div class="newnps-form">
          <input type="text" placeholder="请输入建议或反馈后点击提交" class="newnps-input">
          <span class="newnps-btn">提交</span>
      </div>
      </div>
  </div>
</div>            <div class="template-box">
                <span>©️2022 CSDN</span>
                <span>皮肤主题：精致技术</span>
                <span> 设计师：CSDN官方博客</span>
                <span>
                    <a href="https://blog.csdn.net/" class="back-home c-blue c-blue-hover c-blue-focus">返回首页</a>
                </span>
            </div>
<div class="blog-footer-bottom" style="margin-top:10px;"></div>
<script src="https://g.csdnimg.cn/common/csdn-footer/csdn-footer.js" data-isfootertrack="false" type="text/javascript"></script>
<script type="text/javascript">
    window.csdn.csdnFooter.options = {
        el: '.blog-footer-bottom',
        type: 2
    }
</script>        </main>
<aside class="blog_container_aside">
<div id="asideProfile" class="aside-box">
    <div class="profile-intro d-flex">
        <div class="avatar-box d-flex justify-content-center flex-column">
            <a href="https://blog.csdn.net/weixin_50964512" target="_blank" data-report-click='{"mod":"popu_379","spm":"1001.2101.3001.4121","dest":"https://blog.csdn.net/weixin_50964512","ab":"new"}'>
                <img src="https://profile.csdnimg.cn/4/4/B/3_weixin_50964512" class="avatar_pic">
            </a>
        </div>
        <div class="user-info d-flex flex-column profile-intro-name-box">
            <div class="profile-intro-name-boxTop">
                <a href="https://blog.csdn.net/weixin_50964512" target="_blank" class="" id="uid" title="余识-" data-report-click='{"mod":"popu_379","spm":"1001.2101.3001.4122","dest":"https://blog.csdn.net/weixin_50964512","ab":"new"}'>
                    <span class="name " username="weixin_50964512">余识-</span>
                </a>
                <span>
                </span>
                <span class="flag expert-blog">
                <span class="bubble">CSDN认证博客专家</span>
                </span>
                <span class="flag company-blog">
                <span class="bubble">CSDN认证企业博客</span>
                </span>
            </div>
            <div class="profile-intro-name-boxFooter">
                <span class="personal-home-page personal-home-years" title="已加入 CSDN 2年">码龄2年</span>
                    <span class="personal-home-page">
                    <a class="personal-home-certification" href="https://i.csdn.net/#/uc/profile?utm_source=14998968" target="_blank" title="C/C++领域新星创作者">
                    <img src="https://img-home.csdnimg.cn/images/20210412060958.png" alt="">
                    C/C++领域新星创作者
                    </a>
                    </span>
            </div>
        </div>
    </div>
    <div class="data-info d-flex item-tiling">
        <dl class="text-center" title="76">
            <a href="https://blog.csdn.net/weixin_50964512" data-report-click='{"mod":"1598321000_001","spm":"1001.2101.3001.4310"}' data-report-query="t=1">  
                <dt><span class="count">76</span></dt>
                <dd class="font">原创</dd>
            </a>
        </dl>
        <dl class="text-center" data-report-click='{"mod":"1598321000_002","spm":"1001.2101.3001.4311"}' title="650">
            <a href="https://blog.csdn.net/rank/list/weekly" target="_blank">
                <dt><span class="count">650</span></dt>
                <dd class="font">周排名</dd>
            </a>
        </dl>
        <dl class="text-center" title="13760">
            <a href="https://blog.csdn.net/rank/list/total" data-report-click='{"mod":"1598321000_003","spm":"1001.2101.3001.4312"}' target="_blank">
                <dt><span class="count">1万+</span></dt>
                <dd class="font">总排名</dd>
            </a>
        </dl>
        <dl class="text-center" style="min-width:58px" title="262316">  
            <dt><span class="count">26万+</span></dt>
            <dd>访问</dd>
        </dl>
        <dl class="text-center" title="4级,点击查看等级说明">
            <dt><a href="https://blog.csdn.net/blogdevteam/article/details/103478461" target="_blank">
                <img class="level" src="https://csdnimg.cn/identity/blog4.png">
            </a>
            </dt>
            <dd>等级</dd>
        </dl>
    </div>
    <div class="item-rank"></div>
    <div class="data-info d-flex item-tiling">
        <dl class="text-center" title="1250">
            <dt><span class="count">1250</span></dt>
            <dd>积分</dd>
        </dl>
         <dl class="text-center" id="fanBox" title="20197">
            <dt><span class="count" id="fan">2万+</span></dt>
            <dd>粉丝</dd>
        </dl>
        <dl class="text-center" title="373">
            <dt><span class="count">373</span></dt>
            <dd>获赞</dd>
        </dl>
        <dl class="text-center" title="150">
            <dt><span class="count">150</span></dt>
            <dd>评论</dd>
        </dl>
        <dl class="text-center" title="1376">
            <dt><span class="count">1376</span></dt>
            <dd>收藏</dd>
        </dl>
    </div>
    <div class="aside-box-footer" data-report-view='{"spm":"3001.4296"}'>
        <div class="badge-box d-flex">
            <div class="badge d-flex">
                <div class="icon-badge" title="MarkDown">
                    <div class="mouse-box">
                        <img class="medal-img" data-report-click='{"spm":"3001.4296"}' src="https://csdnimg.cn/11887cd76794439ba69942cd77e81457.png" alt="MarkDown">
                    </div>
                </div>
                <div class="icon-badge" title="新秀勋章">
                    <div class="mouse-box">
                        <img class="medal-img" data-report-click='{"spm":"3001.4296"}' src="https://csdnimg.cn/medal/xinxiu@240.png" alt="新秀勋章">
                    </div>
                </div>
                <div class="icon-badge" title="签到新秀">
                    <div class="mouse-box">
                        <img class="medal-img" data-report-click='{"spm":"3001.4296"}' src="https://csdnimg.cn/medal/qiandao1@240.png" alt="签到新秀">
                    </div>
                </div>
                <div class="icon-badge" title="五一创作勋章">
                    <div class="mouse-box">
                        <img class="medal-img" data-report-click='{"spm":"3001.4296"}' src="https://csdnimg.cn/medal/51_create.png" alt="五一创作勋章">
                    </div>
                </div>
                <div class="icon-badge" title="GitHub">
                    <div class="mouse-box">
                        <img class="medal-img" data-report-click='{"spm":"3001.4296"}' src="https://csdnimg.cn/medal/github@240.png" alt="GitHub">
                    </div>
                </div>
                <div class="icon-badge" title="笔耕不辍">
                    <div class="mouse-box">
                        <img class="medal-img" data-report-click='{"spm":"3001.4296"}' src="https://csdnimg.cn/70592b2299594e37aedcaa91fc52a294.png" alt="笔耕不辍">
                    </div>
                </div>
                <div class="icon-badge" title="阅读者勋章">
                    <div class="mouse-box">
                        <img class="medal-img" data-report-click='{"spm":"3001.4296"}' src="https://csdnimg.cn/medal/yuedu7@240.png" alt="阅读者勋章">
                    </div>
                </div>
                <div class="icon-badge" title="分享学徒">
                    <div class="mouse-box">
                        <img class="medal-img" data-report-click='{"spm":"3001.4296"}' src="https://csdnimg.cn/medal/fenxiangxuetu@240.png" alt="分享学徒">
                    </div>
                </div>
                <div class="icon-badge" title="习惯养成">
                    <div class="mouse-box">
                        <img class="medal-img" data-report-click='{"spm":"3001.4296"}' src="https://csdnimg.cn/medal/xiguanyangchengLv1.png" alt="习惯养成">
                    </div>
                </div>
                <div class="icon-badge" title="分享小兵">
                    <div class="mouse-box">
                        <img class="medal-img" data-report-click='{"spm":"3001.4296"}' src="https://csdnimg.cn/medal/fengxiangxiaobing@240.png" alt="分享小兵">
                    </div>
                </div>
                <div class="icon-badge" title="分享达人">
                    <div class="mouse-box">
                        <img class="medal-img" data-report-click='{"spm":"3001.4296"}' src="https://csdnimg.cn/medal/fenxiangdaren@240.png" alt="分享达人">
                    </div>
                </div>
                <div class="icon-badge" title="持之以恒">
                    <div class="mouse-box">
                        <img class="medal-img" data-report-click='{"spm":"3001.4296"}' src="https://csdnimg.cn/medal/chizhiyiheng@240.png" alt="持之以恒">
                    </div>
                </div>
                <div class="icon-badge" title="勤写标兵">
                    <div class="mouse-box">
                        <img class="medal-img" data-report-click='{"spm":"3001.4296"}' src="https://csdnimg.cn/medal/qixiebiaobing4@240.png" alt="勤写标兵">
                    </div>
                </div>
                <div class="icon-badge" title="成长一夏">
                    <div class="mouse-box">
                        <img class="medal-img" data-report-click='{"spm":"3001.4296"}' src="https://csdnimg.cn/31a4f06ba2fb4bc582766af711746d16.png" alt="成长一夏">
                    </div>
                </div>
            </div>
        </div>
    </div>
    <div class="profile-intro-name-boxOpration">
        <div class="opt-letter-watch-box">
        <a class="bt-button personal-letter" href="https://im.csdn.net/chat/weixin_50964512" target="_blank" rel="noopener">私信</a>
        </div>
        <div class="opt-letter-watch-box"> 
            <a class="personal-watch bt-button" id="btnAttent" >关注</a>  
        </div>
    </div>
</div>
 <div id="asideSearchArticle" class="aside-box">
	<div class="aside-content search-comter">
    <div class="aside-search aside-search-blog">         
        <input type="text" class="input-serch-blog" name="" autocomplete="off" value="" id="search-blog-words" placeholder="搜博主文章">
        <a class="btn-search-blog">
                    <img src="//csdnimg.cn/cdn/content-toolbar/csdn-sou.png?v=1587021042">
        </a>
    </div>
    </div>
</div>

