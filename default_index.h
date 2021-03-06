#ifndef _DEFAULT_INDEX_H_
#define _DEFAULT_INDEX_H_

const char* strDefaultIndex = R"(
<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="">
    <meta name="author" content="">
    <link rel="icon" href="../../favicon.ico">
    <title>NetDisk</title>

    <style type="text/css">
        body {
            padding-top: 50px;
        }

        .starter-template {
            padding: 40px 15px;
            text-align: left;
        }

        @-ms-viewport {
            width: device-width;
        }

        @-o-viewport {
            width: device-width;
        }

        @viewport {
            width: device-width;
        }
    </style>

    <!-- Bootstrap -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@3.3.7/dist/css/bootstrap.min.css" rel="stylesheet">
</head>

<body>
    <div class="container">

        <div class="starter-template">
            <h1>在线网盘</h1>
            <p class="lead">文件目录</p>
            <hr />
            <p><a href="/">首页</a></p>
            <hr />
            {% if exists("filelist") %}
            {% for file in filelist %}
            {% if file.isDir == true %}
            <p><input name="Fruit" type="checkbox" value="" />&nbsp<a href="{{file.fullPath}}">{{file.fileName}}</a></p>
            {% else %}
            <p><input name="Fruit" type="checkbox" value="" />&nbsp<a href="{{file.fullPath}}" download="{{file.fileName}}">{{file.fileName}}</a></p>
            {% endif %}
            {% endfor %}
            {% endif %}

            <form id="formElem">
                <input type="file" name="file" accept="all/*">
                <input type="submit" value="上传文件">
            </form>
        </div>

    </div><!-- /.container -->



    <script>
        formElem.onsubmit = async (e) => {
        e.preventDefault();
        let res = await fetch('/post', {
        method: 'POST',
        body: new FormData(formElem)
        });
        console.log(await res.text());
        location.reload(true)
        };
    </script>

    <!-- jQuery (Bootstrap 的所有 JavaScript 插件都依赖 jQuery，所以必须放在前边) -->
    <script src="https://cdn.jsdelivr.net/npm/jquery@1.12.4/dist/jquery.min.js"></script>
    <!-- 加载 Bootstrap 的所有 JavaScript 插件。你也可以根据需要只加载单个插件。 -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@3.3.7/dist/js/bootstrap.min.js"></script>
</body>
</html>
)";

#endif