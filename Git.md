﻿# Git
`Git`은 분산 버전 관리 시스템 중 하나로, 소스 코드의 버전을 관리하고 추적하는 도구입니다. 리누스 토르발스(Linus Torvalds)가 개발했으며, 현재는 소프트웨어 개발에서 널리 사용되고 있습니다.

## commit
`커밋(commit)`은 파일의 변경 사항을 저장하는 작업입니다. 커밋에는 해당 시점의 파일 상태, 작업한 개발자의 정보, 커밋 메시지(변경 사항에 대한 설명) 등이 포함됩니다.

커밋을 통해 Git은 파일의 변경 이력을 관리하고, 이전 상태로 롤백하거나 변경 사항을 추적할 수 있습니다.

## branch
`브랜치(branch)`는 독립적인 작업 흐름으로, 상태(파일, 커밋 정보 등)를 저장하는 공간입니다. 기존의 코드나 프로젝트에서 분기하여 새로운 작업을 시작하기 위한 가상의 포인트로 볼 수 있습니다. 브랜치에서는 기존의 코드를 기반으로 새로운 기능을 개발하거나 버그를 수정할 수 있으며, 이 작업은 다른 브랜치에 영향을 주지 않습니다.

어떤 브랜치를 기반으로 언제든지 새로운 브랜치를 만들 수 있습니다. 또한 각 브랜치는 고유한 커밋 이력을 가지고 있으며, 작업이 완료되면 필요에 따라 원하는 브랜치와 병합할 수도 있습니다.

```
master -----c1-1---------------c1-2-------->
                       |
                    b1 |-------c2-1-------->

※ b1의 작업은 master에 영향을 주지 않습니다.
```

### master branch
처음 Git 저장소를 만들면 `master`라는 기본 브랜치가 생성됩니다. (`main`, `default` 브랜치라고도 합니다.) 이후 기본 브랜치를 기반으로 새로운 브랜치를 만들 수 있습니다.

기본 브랜치는 삭제할 수 없으며, 다른 브랜치를 기본 브랜치로 변경할 수 없습니다.

## merge
브랜치 병합은 현재 브랜치를 다른 브랜치와 결합하여 단일 브랜치로 합치는 작업입니다. 즉, 두 브랜치의 커밋 히스토리를 합쳐서 하나의 새로운 커밋을 만듭니다. 병합을 수행한 이후에도 다른 브랜치는 삭제되지 않고 계속 사용이 가능합니다.

브랜치 병합에는 `merge`, `squash`, `rebase` 등의 방식이 있습니다.

### merge
`merge`는 두 브랜치의 커밋 히스토리를 합쳐서 하나의 새로운 커밋을 만드는 병합 방식입니다. 새로 만들어진 커밋은 두 브랜치의 커밋 히스토리에 각각 추가됩니다.

```
> master에서 b1와 merge 수행

master -----c(m,1)---------c(m,2)---c(m,3)----c(mb,1)------>
                       |                      |
                    b1 |---c(b,1)---c(b,2)----c(mb,1)------>
```

merge 방식은 주로 기존 브랜치에서 새로운 기능이나 수정된 코드를 받아들일 때 사용됩니다.

### squash
`squash`는 다른 브랜치의 여러 개의 연속적인 커밋을 하나의 커밋으로 합쳐 현재 브랜치의 커밋 히스토리 마지막에 추가하는 병합 방식입니다. 다른 브랜치에는 별도의 커밋이 추가되지 않습니다.

```
> master에서 b1와 squash 수행

master -----c(m,1)---------c(m,2)---c(m,3)----c(b,m1)------>
                       |                      |
                    b1 |---c(b,1)---c(b,2)----------------->
```

squash 방식을 사용하면 과도한 커밋 메시지를 줄이고, 코드 변경 사항을 더 깔끔하게 유지할 수 있다는 이점이 있습니다.

### rebase
`rebase`는 다른 브랜치의 모든 커밋을 현재 브랜치의 커밋 히스토리 마지막에 추가하는 병합 방식입니다. 다른 브랜치에는 별도의 커밋이 추가되지 않습니다.

```
> master에서 b1와 rebase 수행

master -----c(m,1)---------c(m,2)---c(m,3)----c(b,1),c(b,2)--->
                       |                      |
                    b1 |---c(b,1)---c(b,2)-------------------->
```

rebase 방식은 브랜치의 기록을 다른 브랜치와 조정하거나 깔끔하게 정리할 때 사용됩니다.

## checkout
`checkout`은 Git 작업 디렉토리를 변경하는 작업입니다. 주로 다음 목적으로 사용됩니다.

- 브랜치 간의 전환
- 특정 커밋, 파일로 이동
- 파일을 이전 상태로 복원

## conflict
`충돌(conflict)`는 Git이 자동으로 처리할 수 없는 발생하는 상황으로, 주로 브랜치 통합 작업 시 발생합니다. 충돌이 발생하면, 충돌이 일어난 파일을 직접 열어 수동으로 해결해야 합니다.

```
ex.
> File A
a = 1, b = 2;
print(a + b);

> File B
a = 1, b = 2;
print(a - b);
```

위의 두 파일을 병합하면 아래와 같은 양식으로 추가됩니다. 문제의 부분을 수정하고 다시 병합을 실행하면 충돌이 해결됩니다.
```
a = 1, b = 2;
>>>>>>>HEAD
print(a + b);
-------------------------
print(a - b);
<<<<<<<assdda
```

## 원격 저장소
Git에서는 일반적으로 여러 명의 개발자가 동일한 프로젝트에 참여하고 작업하기 위해 `원격 저장소`를 사용합니다. `로컬 컴퓨터`에서 작업을 하고 이를 원격 저장소로 보내거나, 원격 저장소로부터 변경 사항을 로컬로 가져올 수 있습니다.

### origin  
`origin`은 기본적인 Git의 원격 저장소 이름 중 하나입니다. 설정에서 다른 이름으로 변경할 수 있습니다.

## push & pull
`push`는 로컬 저장소의 변경 사항을 원격 저장소로 업로드하는 작업이며, `pull`은 원격 저장소의 변경 사항을 로컬 저장소로 가져오는 작업입니다. 이 두 작업은 push와 pull은 로컬 저장소와 원격 저장소 간의 브랜치를 통합하는 것으로, 차이는 통합하는 방향에 있습니다. push는 로컬 브랜치를 원격 브랜치로 병합하고, pull은 원격 브랜치를 로컬 브랜치로 병합합니다. 예를 들어, 로컬 저장소의 브랜치 A에서 push를 수행하면, 브랜치 A의 변경 사항이 원격 저장소의 브랜치 A에 반영됩니다.

만약 push 또는 pull을 수행할 때 대상 저장소에 브랜치가 존재하지 않으면, 해당 저장소에서 자동으로 해당 브랜치가 새로 생성됩니다.

로컬 저장소의 변경 사항을 원격 저장소에 반영하기 전에는, 로컬 저장소의 상태가 원격 저장소와 일치해야 합니다. 따라서 push를 수행하기 전에는 먼저 pull을 수행할 필요가 있습니다.

pull을 수행하기 전에는 git directory 상태와 working directory 상태가 일치해야 합니다. 즉, 수정한 파일을 커밋하지 않은 경우에는 pull을 수행할 수 없습니다.

## pull request
`pull request`는 협업 과정에서 코드 변경 사항을 다른 사람들과 리뷰하고 병합하기 위해 사용되는 기능입니다. 주로 오픈 소스 프로젝트에서 코드 변경을 제안하고 검토하는 과정을 효율적으로 진행하기 위한 도구이며, 코드의 품질 향상과 협업을 원활하게 수행할 수 있도록 돕습니다.

일반적인 pull request 프로세스는 다음과 같습니다:
1. **기능 추가 또는 수정:** 개발자가 자신의 로컬 브랜치에서 코드를 수정하거나 새로운 기능을 개발합니다.
2. **변경 사항을 원격 저장소에 push:** 개발자는 로컬에서 작업한 변경 사항을 원격 저장소로 push하여 해당 변경 사항이 원격 저장소에 반영됩니다.
3. **pull request 생성:** 개발자는 원격 저장소에서 자신이 작업한 브랜치를 기준으로 다른 브랜치(일반적으로 기본 브랜치)에 대한 변경 사항을 요청하는 풀 리퀘스트를 생성합니다.
4. **리뷰 및 논의:** 다른 개발자들은 해당 pull request에 대해 변경 사항을 검토하고 논의합니다. 코드 리뷰, 토론, 수정 제안 등을 통해 코드 품질을 향상시키고 협업을 진행합니다.
5. **병합:** 코드 검토가 완료되고 승인이 이루어지면 해당 풀 리퀘스트는 원하는 변경 사항을 대상 브랜치로 병합하여 이를 반영합니다.

## File Status Lifecycle
Git에서 파일들은 `Modified`, `Staged`, `Committed` 세 가지 상태를 가질 수 있습니다.

1. `Modified`: 파일이 수정된 상태입니다. 파일 내용이 변경되었지만 아직 Git에 의해 추적되거나 저장소에 커밋되지 않은 상태를 말합니다.
2. `Staged`: 수정된 파일 중에서 커밋에 포함할 준비가 된 파일입니다. 개발자가 수정한 내용을 staging area에 추가하여, 커밋할 변경 사항을 표시해둔 상태입니다.
3. `Committed`: 파일이 로컬 저장소에 안전하게 저장된 상태입니다. 이것은 스테이징된 파일들이 커밋되어 저장소의 특정 버전에 영구적으로 기록된 상태를 의미합니다. 커밋된 파일은 변경 이력을 가지며, 안전하게 저장되어 언제든지 복구하거나 버전을 확인할 수 있습니다.

## Workspace
Git은 프로젝트를 관리하기 위해 `Git Directory`, `Working Directory`, `Staging Area`라는 세 가지 주요 영역으로 구성됩니다.

### Git Directory
`Git Directory`는 `.git` 디렉토리라고도 불리며, Git에서 프로젝트의 모든 버전 관리 정보와 이력을 저장하는 숨겨진 폴더입니다. 이 디렉토리는 Git으로 관리되는 프로젝트의 루트 디렉토리에 배치됩니다. `.git` 폴더에는 객체 데이터베이스, 참조, 커밋 로그 등을 포함합니다.
  
일반적으로 사용자가 `.git` 디렉토리에 직접적으로 작업할 필요는 없습니다.

### Working Directory
`Working Directory`는 프로젝트의 실제 파일들이 존재하는 디렉토리입니다. 여기서 개발자는 파일을 생성, 수정, 삭제하는 등의 작업을 수행합니다.

### Staging Area
`Staging Area`는 변경된 파일들 중에서 커밋에 포함될 파일을 선택하는 곳입니다. 이 영역에 추가된 파일은 `Staged` 상태를 갖습니다.

## stage
`stage`는 Git에서 파일을 준비 상태로 만들어 커밋할 준비를 하는 과정입니다. 다른 버전 관리 시스템에는 없는 Git의 독특한 개념 중 하나입니다. stage의 개념을 활용함으로써 변경 이력을 더 작고 의미 있는 단위로 관리할 수 있습니다.

GitHub Desktop 등의 일부 GUI 도구는 사용자에게 직접적인 stage 과정을 보여주지 않을 수 있습니다. 하지만 내부적으로는 변경된 파일을 stage에 올리고 커밋하는 과정이 수행됩니다. 이러한 도구를 사용하면 명시적인 stage 단계를 거치지 않더라도 사용자가 변경 사항을 선택하고 커밋할 수 있습니다.

## .gitignore
`.gitignore` 파일은 Git에서 추적하지 않을 파일 및 디렉토리를 지정하는 데 사용되는 설정 파일로, 프로젝트 루트 디렉토리에 위치합니다. Git이 해당 디렉토리와 그 하위 디렉토리에서 파일을 추적할 때 `.gitignore`에 명시된 규칙을 적용합니다.

일반적으로 로그 파일, 컴파일된 코드, 캐시 파일 등을 `.gitignore` 파일에 추가하여 Git 추적 대상에서 제외시킵니다. 이렇게 하면 이러한 파일들이 저장소에 커밋되지 않아 코드를 관리할 때 문제가 발생하지 않습니다.

`.gitignore` 파일은 각 행마다 패턴을 지정하고 해당 패턴에 맞는 파일이나 디렉토리를 무시하도록 지시합니다. 예를 들어, 다음과 같이 패턴을 지정할 수 있습니다:
```
# 주석은 '#'으로 시작
# 특정 파일 무시
file_to_ignore.txt

# 특정 디렉토리 무시
directory_to_ignore/

# 특정 확장자 무시
*.log

# 특정 패턴 예외
!important_file.txt
```

위 예제에서 `file_to_ignore.txt`는 무시되고, `directory_to_ignore/` 디렉토리 내의 모든 파일과 `.log` 확장자를 가진 파일들은 무시됩니다. 그러나 `important_file.txt`는 예외로 무시되지 않고 추적됩니다.