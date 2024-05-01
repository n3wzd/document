# Django
Django는 파이썬으로 작성된 오픈 소스 웹 애플리케이션 프레임워크입니다. 웹 개발을 보다 쉽고 빠르게 할 수 있도록 도와주는 도구와 기능을 제공합니다. Django는 MTV(Model-Template-View) 패턴을 따르며, 이는 모델, 템플릿 및 뷰로 구성됩니다.

- **완전한 웹 프레임워크**: Django는 웹 개발에 필요한 거의 모든 기능을 갖춘 완전한 웹 프레임워크입니다. 데이터베이스 관리, URL 라우팅, 세션 관리, 폼 처리, 보안 등을 포함합니다.
- **강력한 ORM(객체 관계 매핑)**: Django의 ORM은 데이터베이스와의 상호 작용을 추상화하여 개발자들이 SQL 쿼리를 직접 작성하지 않고도 데이터베이스를 조작할 수 있게 해줍니다.
- **관리자 인터페이스**: Django는 모델을 기반으로 자동으로 관리자 인터페이스를 생성해주는 기능을 제공합니다. 이를 통해 데이터베이스 관리가 용이해지고, 개발자들은 관리자 페이지를 통해 데이터를 쉽게 관리할 수 있습니다.
- **확장 가능성**: Django는 다양한 라이브러리와 플러그인을 통해 확장 가능합니다. 이러한 확장성은 프로젝트 요구 사항에 맞게 Django 애플리케이션을 더욱 강력하고 유연하게 만들어 줍니다.

## 뷰 (View)
뷰(View)는 웹 애플리케이션의 로직을 처리하고 클라이언트에게 응답을 반환하는 부분을 말합니다. 즉, 사용자의 요청을 처리하고 적절한 데이터를 템플릿에 전달하여 동적인 웹 페이지를 생성하는 역할을 합니다.

Django에서 뷰는 함수 기반 뷰(Function-Based Views)와 클래스 기반 뷰(Class-Based Views)로 구현할 수 있습니다.  일반적으로는 간단한 프로젝트나 기능을 구현할 때는 함수 기반 뷰가 적합하며, 프로젝트의 규모가 커지거나 재사용성이 높은 코드가 필요할 때는 클래스 기반 뷰를 사용하는 것이 좋습니다.

### 함수 기반 뷰(Function-Based Views)
가장 간단한 형태의 뷰로, 파이썬 함수로 구현됩니다. 함수는 HTTP 요청을 인자로 받고 HTTP 응답을 반환합니다.

- 간단하고 직관적입니다. 특히 작은 프로젝트나 간단한 기능을 구현할 때 유용합니다.
- 코드의 중복이 발생할 수 있습니다. 또한 기능이 복잡해지면 유지보수가 어려워질 수 있습니다. 

```
from django.http import HttpResponse
from django.shortcuts import render

def hello(request):
    return HttpResponse("Hello, world!")

def greeting(request, name):
    return HttpResponse(f"Hello, {name}!")
```

### 클래스 기반 뷰(Class-Based Views)
클래스로 뷰를 정의하며, Django의 제네릭 뷰를 상속하여 보다 간편하고 재사용 가능한 뷰를 작성할 수 있습니다. 클래스는 HTTP 요청에 대한 다양한 메서드(예: `get()`, `post()`)를 제공하여 각각의 HTTP 메서드에 대한 로직을 구현합니다.

- 코드 재사용성이 높고, 코드 구조화를 할 수 있습니다. 각 HTTP 메서드에 대한 로직을 메서드로 분리하여 가독성이 향상됩니다.
- 함수 기반 뷰보다 조금 더 복잡하고 코드 양이 많을 수 있습니다.

```
from django.http import HttpResponse
from django.views import View

class HelloView(View):
    def get(self, request):
        return HttpResponse("Hello, world!")

class GreetingView(View):
    def get(self, request, name):
        return HttpResponse(f"Hello, {name}!")
```

## URL
URL은 사용자가 요청한 웹 페이지를 식별하는 데 사용됩니다. URL 패턴은 웹 애플리케이션의 각 뷰와 연결되어 요청된 URL에 따라 적절한 뷰로 라우팅됩니다.

Django의 URL 패턴은 주로 URL 패턴과 해당 뷰 또는 뷰 클래스를 연결하는 URLconf(URI Configuration) 파일에 정의됩니다. URLconf는 다음 두 가지 유형으로 나뉩니다.

### 프로젝트 레벨 URLconf
Django 프로젝트의 최상위 디렉터리에 위치하며, 전체 프로젝트의 URL 패턴을 관리합니다. 이 파일은 일반적으로 `urls.py`라는 이름으로 작성됩니다.

```
from django.urls import path, include

urlpatterns = [
    path('todo/', include('todo.urls')),
]
```

### 애플리케이션 레벨 URLconf
각 Django 애플리케이션 내부에 위치하며, 해당 애플리케이션에 속한 뷰와 연결된 URL 패턴을 정의합니다. 이 파일은 일반적으로 애플리케이션의 디렉터리에 `urls.py`라는 이름으로 작성됩니다.

```
from django.urls import path
from . import views

urlpatterns = [
    path('', views.task_list, name='task_list'),
    path('add/', views.add_task, name='add_task'),
]
```

## 템플릿 (Template)
템플릿은 동적인 웹 페이지를 생성하기 위해 사용되는 파일입니다. 템플릿은 HTML, CSS, JavaScript 및 Django의 템플릿 언어(Template Language)를 결합하여 사용자에게 동적으로 생성된 콘텐츠를 제공합니다. Django의 템플릿 엔진은 템플릿을 렌더링하여 최종 HTML 페이지를 생성하는 역할을 합니다.

템플릿은 다음과 같은 기능을 제공합니다:
- **템플릿 변수(Variables)**: 템플릿 내에서 파이썬 코드와 함께 사용되는 변수를 의미합니다. 이러한 변수는 템플릿 엔진에 의해 렌더링되어 최종 HTML 페이지에 동적으로 표시됩니다. 예를 들어, 데이터베이스에서 가져온 사용자 이름이나 특정 조건에 따라 다르게 표시되는 콘텐츠 등이 해당됩니다.
- **템플릿 태그(Tags)**: 템플릿 내에서 흐름 제어, 반복, 조건 처리 등과 같은 기능을 수행하는 특별한 구문을 나타냅니다. 예를 들어, `{% if %}`, `{% for %}`, `{% include %}`와 같은 템플릿 태그를 사용하여 템플릿의 동작을 제어할 수 있습니다.   
- **템플릿 필터(Filters)**: 템플릿 변수의 출력 값을 변환하거나 포맷하는 데 사용됩니다. 예를 들어, 문자열을 대문자로 변환하거나 날짜를 특정 형식으로 표시하는 등의 작업을 수행할 수 있습니다.

```
<!-- example_template.html -->
<!DOCTYPE html>
<html>
<head>
    <title>{{ title }}</title>
</head>
<body>
    <h1>{{ heading }}</h1>
    <ul>
        {% for item in items %}
            <li>{{ item }}</li>
        {% endfor %}
    </ul>
</body>
</html>
```

## 모델 (Model)
모델(Model)은 데이터베이스의 구조를 정의하고 데이터베이스와의 상호 작용을 쉽게 처리할 수 있도록 도와주는 파이썬 클래스입니다. 각 모델 클래스는 데이터베이스의 테이블에 대응하며, 모델 클래스의 속성은 테이블의 열(Column)에 해당합니다. Django는 이 모델을 기반으로 데이터를 저장, 수정, 검색 및 삭제할 수 있는 객체 관계 매핑(ORM) 시스템을 제공합니다.

Django 모델은 다음 과정에 따라 구현됩니다:
1. **모델 클래스 정의**: 모델 클래스는 `django.db.models.Model` 클래스를 상속하여 정의됩니다. 각 모델 클래스의 속성은 데이터베이스의 필드에 해당하며, 각 필드는 데이터베이스 테이블의 열을 나타냅니다.
2. **필드 타입 정의**: Django는 다양한 데이터베이스 필드 타입을 제공하여 다양한 유형의 데이터를 저장할 수 있습니다. 예를 들어, 문자열, 숫자, 날짜, 시간, 관계 등을 저장할 수 있습니다.
3. **모델 관계 정의**: 모델 간의 관계를 설정할 수 있습니다. ForeignKey, OneToOneField, ManyToManyField 등의 필드를 사용하여 모델 간의 관계를 표현할 수 있습니다.
4. **데이터베이스 테이블 생성**: 모델 클래스를 정의한 후에는 Django의 마이그레이션(Migration) 도구를 사용하여 데이터베이스에 해당 모델에 대한 테이블을 생성할 수 있습니다.
5. **ORM을 통한 데이터 작업**: Django의 ORM은 모델 클래스를 사용하여 데이터베이스 작업을 수행할 수 있도록 합니다. 데이터를 생성, 읽기, 업데이트, 삭제하는 다양한 메서드를 제공하여 간단하게 데이터를 다룰 수 있습니다.
6. **관리자 인터페이스 자동 생성**: Django는 모델 클래스를 기반으로 관리자 인터페이스를 자동으로 생성합니다. 이를 통해 데이터베이스의 데이터를 쉽게 관리할 수 있습니다.

```
from django.db import models

class Book(models.Model):
    title = models.CharField(max_length=100)
    author = models.CharField(max_length=50)
    publication_date = models.DateField()

    def __str__(self):
        return self.title
```
### ORM
아래 메서드들은 Django의 ORM을 통해 데이터베이스에 실제로 쿼리를 보내어 데이터를 제어합니다. 각 메서드는 데이터베이스의 INSERT, UPDATE, DELETE 쿼리를 생성하고 실행합니다. 

#### 데이터 추가 (Insert)
새로운 데이터를 추가하려면 모델 클래스의 객체를 생성하고 필드에 원하는 값을 할당한 후, `save()` 메서드를 호출하여 데이터베이스에 저장합니다.

```
from myapp.models import MyModel

# 새로운 객체 생성
new_object = MyModel(field1=value1, field2=value2, ...)

# 데이터베이스에 저장
new_object.save()
```

#### 데이터 업데이트 (Update)
기존 데이터를 업데이트하려면 해당 객체를 가져온 후 필드 값을 변경하고 `save()` 메서드를 호출합니다.

```
from myapp.models import MyModel

# 기존 객체 가져오기
object_to_update = MyModel.objects.get(id=1)

# 필드 값 변경
object_to_update.field1 = new_value1
object_to_update.field2 = new_value2

# 업데이트된 데이터베이스에 저장
object_to_update.save()
```

#### 데이터 삭제 (Delete)
데이터를 삭제하려면 해당 객체를 가져온 후 `delete()` 메서드를 호출합니다.

```
from myapp.models import MyModel

# 삭제할 객체 가져오기
object_to_delete = MyModel.objects.get(id=1)

# 데이터베이스에서 삭제
object_to_delete.delete()
```

### 모델 업데이트
모델 자체를 업데이트는 데이터베이스 스키마의 변경이나 초기 데이터의 추가 등을 의미합니다. Django에서 모델 자체를 업데이트하는 방법은 다음과 같습니다.

- **모델 필드 추가 및 수정**: 모델에 새로운 필드를 추가하거나 기존 필드의 속성을 수정할 때는 모델 클래스를 직접 수정합니다. 필드를 추가하거나 수정한 후에는 `makemigrations` 명령을 사용하여 마이그레이션 파일을 생성하고, `migrate` 명령을 사용하여 데이터베이스에 변경 사항을 적용합니다.
- **모델 메서드 추가**: 모델에 새로운 메서드를 추가할 수도 있습니다. 이러한 메서드는 모델 인스턴스에서 호출하여 특정 작업을 수행하거나 계산을 수행할 수 있습니다. 모델 클래스에 메서드를 추가하면 해당 모델의 모든 인스턴스에서 사용할 수 있습니다.
- **모델 데이터 추가**: 모델에 초기 데이터를 추가하려면 Django의 데이터 마이그레이션 기능을 사용하여 데이터베이스에 새로운 레코드를 추가할 수 있습니다. 이를 위해 데이터 마이그레이션 파일에 초기 데이터를 포함시키거나 Django의 Fixture 기능을 사용하여 초기 데이터를 로드할 수 있습니다.
- **모델 제거**: 필요 없는 모델을 삭제하려면 해당 모델 클래스를 삭제하고, `makemigrations` 및 `migrate` 명령을 사용하여 변경 사항을 데이터베이스에 적용합니다.
