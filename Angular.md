# Angular
Google에서 개발한 Angular는 TypeScript를 기반으로 한 오픈 소스 프론트엔드 웹 애플리케이션 프레임워크입니다.

- **MVC(모델-뷰-컨트롤러) 아키텍처 패턴**: Angular 애플리케이션은 컴포넌트라고 불리는 작은 단위로 구성됩니다. 각 컴포넌트는 자체적인 뷰와 로직을 가지며, 이를 조합하여 애플리케이션을 구축할 수 있습니다.  
- **데이터 바인딩**: Angular는 양방향 데이터 바인딩을 지원하여 모델과 뷰 간의 상호 작용을 간편하게 할 수 있습니다. 이를 통해 모델의 변경이 자동으로 뷰에 반영되고, 뷰의 변경도 모델에 반영됩니다.
- **의존성 주입(Dependency Injection)**: Angular는 의존성 주입을 통해 컴포넌트 간의 의존성을 관리하고 컴포넌트를 쉽게 테스트할 수 있도록 합니다.
- **단일 페이지 애플리케이션(Single Page Application, SPA)**: Angular는 SPA를 쉽게 개발할 수 있도록 도와줍니다. 이를 통해 웹 애플리케이션이 빠르고 반응성 있게 동작하며, 사용자 경험을 향상시킬 수 있습니다.

## 컴포넌트 (Component)
Angular에서 컴포넌트(Component)는 사용자 인터페이스의 부분을 정의하고 해당 부분을 독립적으로 관리하는 빌딩 블록입니다. 각 컴포넌트는 자체적인 뷰와 로직을 가지며, 재사용 가능하고 독립적으로 테스트할 수 있습니다. Angular 애플리케이션은 이러한 컴포넌트들의 계층 구조로 구성됩니다.

Angular 컴포넌트는 `@Component` 데코레이터를 사용하여 정의됩니다. 이 데코레이터에는 컴포넌트와 관련된 메타데이터가 포함됩니다. (템플릿 파일의 경로, CSS 파일의 경로, 컴포넌트의 선택자 등)

```
// todo-list-item.component.ts
@Component({
  standalone: true,
  selector: 'todo-list-item',
  template: ` <li>(TODO) Read cup of coffee introduction</li> `,
  styles: ['li { color: papayawhip; }'],
})
export class TodoListItem {
  /* 컴포넌트의 동작은 여기에 정의합니다. */
}
```
### 상태
컴포넌트의 상태는 컴포넌트 클래스의 프로퍼티로 정의합니다.

```
// todo-list-item.component.ts
@Component({ ... })
export class TodoList {
  taskTitle = '';
  isComplete = false;
}
```

### 메서드
컴포넌트의 동작은 컴포넌트 클래스의 메서드로 정의합니다.

```
// todo-list-item.component.ts
@Component({ ... })
export class TodoList {
  taskTitle = '';
  isComplete = false;

  updateTitle(newTitle: string) {
    this.taskTitle = newTitle;
  }

  completeTask() {
    this.isComplete = true;
  }
}
```

### 생명주기(Lifecycle) 훅
Angular 컴포넌트는 생성, 변경, 파괴 등의 생명주기 이벤트에 대한 훅을 제공합니다. 이를 통해 컴포넌트가 초기화되거나 파괴되는 시점에 특정 동작을 수행할 수 있습니다.

|훅|기능|
|---|---|
|`ngOnChanges`|컴포넌트의 입력 프로퍼티가 변경될 때마다 호출됩니다.|
|`ngOnInit`|컴포넌트가 초기화될 때 한 번만 호출됩니다.|
|`ngDoCheck`|Angular의 변화 감지(Change Detection)가 실행될 때마다 호출됩니다.|
|`ngAfterContentInit`|컴포넌트의 내용이 초기화된 후에 호출됩니다.|
|`ngAfterContentChecked`|컴포넌트의 내용 변화 감지가 실행된 후에 호출됩니다.|
|`ngAfterViewInit`|컴포넌트의 뷰가 초기화된 후에 호출됩니다.|
|`ngAfterViewChecked`|뷰의 변화 감지가 실행된 후에 호출됩니다.|
|`ngOnDestroy`|컴포넌트가 파괴되기 직전에 호출됩니다.|

```
import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-example',
  template: '<p>{{ message }}</p>'
})
export class ExampleComponent implements OnInit {
  message: string = '';

  ngOnInit(): void {
    this.message = '컴포넌트가 초기화되었습니다.';
  }
}
```

## HTML 템플릿
Angular에서의 뷰(View)는 사용자에게 표시되는 부분이며, HTML 템플릿을 사용하여 작성됩니다. HTML 템플릿은 일반적인 HTML 코드와 Angular 템플릿 문법을 혼합하여 사용됩니다.

```
<!-- todo-list.component.html -->
<div>
  <h2>할 일 목록</h2>
  <input type="text" [(ngModel)]="newTodo" placeholder="할 일을 입력하세요">
  <button (click)="addTodo()">추가</button>
  <ul>
    <li *ngFor="let todo of todos">
      <input type="checkbox" [(ngModel)]="todo.completed">
      <span [ngClass]="{'completed': todo.completed}">{{ todo.text }}</span>
    </li>
  </ul>
</div>
```

### 바인딩
2개의 중괄호(`{{ }}`)를 사용하여 데이터 바인딩을 표현합니다.

```
@Component({
  template: ` <p>Title: {{ taskTitle }}</p> `,
})
export class TodoListItem {
  taskTitle = 'Read cup of coffee';
}
```

### 동적 속성
동적으로 변경될 속성에 대괄호(`[ ]`)를 사용합니다.

```
<button [disabled]="hasPendingChanges"></button>
```

### 이벤트 핸들링
이벤트 속성에 괄호(`( )`)를 추가하여 이벤트 리스너를 컴포넌트 메서드와 연결합니다. 이벤트 리스너로 이벤트 객체를 전달할 때는  `$event`  변수를 사용합니다.

```
<button (click)="saveChanges($event)">Save Changes</button>
```

## 스타일
스타일을 지정하는 방법은 2가지가 있습니다:
-  `@[Component]` 의  `styles`  프로퍼티
-  `styleUrls`  프로퍼티

스타일 문법은 CSS 스타일을 사용합니다.

```
@Component({
  selector: 'profile-pic',
  template: `<img src="profile-photo.jpg" alt="Your profile photo" />`,
  styles: [
    `
      img {
        border-radius: 50%;
      }
    `,
  ],
})
export class ProfilePic {
  /* 컴포넌트 코드는 여기 작성합니다. */
}
```

## 디렉티브 (Directives)
Angular의 디렉티브는 HTML 요소의 동작이나 모양을 변경하거나 확장할 수 있는 기능을 제공합니다. 예를 들어, `*ngFor` 디렉티브는 배열에 대해 반복하고

### *ngIf
`*ngIf` 디렉티브는 표현식이 참으로 평가될 때 해당 엘리먼트를 화면에 렌더링합니다.

```
<section class="admin-controls" *ngIf="hasAdminPrivileges">
  The content you are looking for is here.
</section>
```

### *ngFor
`*ngFor` 디렉티브는 주어진 배열에 대해 반복하여 해당 엘리먼트를 화면에 렌더링합니다.

```
<ul class="ingredient-list">
  <li *ngFor="let task of taskList">{{ task }}</li>
</ul>
```

### 커스텀 디렉티브
커스텀 디렉티브를 사용해서 특정한 동작을 정의할 수 있습니다.

- 데코레이터(`@Directive`)에는 디렉티브의 옵션을 지정합니다:
	- `selector`: 디렉티브 이름을 설정합니다.
- TypeScript 클래스는 디렉티브의 동작을 정의합니다.

```
@Directive({
  selector: '[appHighlight]',
})
export class HighlightDirective {
  private el = inject(ElementRef);
  constructor() {
    this.el.nativeElement.style.backgroundColor = 'yellow';
  }
}
```

```
<p  appHighlight>Look at me!</p>
```

## 서비스(Services)
서비스는 컴포넌트끼리 공유할 수 있는 동작입니다.

- 데코레이터(`@Injectable`)에는 서비스의 옵션을 지정합니다:
	- `providedIn`: 서비스 적용 영역을 정의합니다.
		- `root`:  애플리케이션 전역
- TypeScript 클래스는 서비스의 동작을 정의합니다.

```
import {Injectable} from '@angular/core';

@Injectable({
  providedIn: 'root',
})
class CalculatorService {
  add(x: number, y: number) {
    return x + y;
  }
}
```

정의한 서비스는 의존성 주입을 통해 컴포넌트에 주입하여 사용할 수 있습니다. (`inject` 함수를 사용합니다.)

```
import { Component } from '@angular/core';
import { CalculatorService } from './calculator.service';

@Component({
  selector: 'app-receipt',
  template: `<h1>The total is {{ totalCost }}</h1>`,
})
export class Receipt {
  private calculatorService = inject(CalculatorService);
  totalCost = this.calculatorService.add(50, 25);
}
```
