# Пошаговая сборка VexGram.ipa через GitHub Actions

Инструкция для сборки IPA на Windows (или без Mac): код хранится на GitHub, сборка выполняется на виртуальном Mac в GitHub Actions, готовый **VexGram.ipa** можно скачать из интерфейса GitHub.

---

## Что понадобится

- Аккаунт на [GitHub](https://github.com)
- Git на компьютере (или GitHub Desktop)
- Репозиторий VexGram (этот проект) на вашем GitHub

---

## Шаг 1. Создать репозиторий на GitHub

1. Зайдите на [github.com](https://github.com) и войдите в аккаунт.
2. Нажмите **«+»** в правом верхнем углу → **«New repository»**.
3. Укажите:
   - **Repository name:** например `VexGram` или `Swiftgram`.
   - **Visibility:** Public или Private — на сборку не влияет.
   - Не добавляйте README, .gitignore и лицензию — репозиторий должен быть пустым.
4. Нажмите **«Create repository»**.

---

## Шаг 2. Загрузить проект в репозиторий

На компьютере откройте терминал (PowerShell или командную строку) в папке с проектом VexGram.

### Если папка ещё не под Git:

```powershell
cd "d:\Новая папка (2)\Swiftgram"
git init
git add .
git commit -m "Initial commit: VexGram"
git branch -M main
git remote add origin https://github.com/ВАШ_ЛОГИН/ВАШ_РЕПОЗИТОРИЙ.git
git push -u origin main
```

Замените `ВАШ_ЛОГИН` на ваш логин GitHub и `ВАШ_РЕПОЗИТОРИЙ` на имя репозитория (например `VexGram`).

### Если проект уже в Git:

```powershell
cd "d:\Новая папка (2)\Swiftgram"
git remote add origin https://github.com/ВАШ_ЛОГИН/ВАШ_РЕПОЗИТОРИЙ.git
git push -u origin main
```

Если `origin` уже есть, замените его:

```powershell
git remote set-url origin https://github.com/ВАШ_ЛОГИН/ВАШ_РЕПОЗИТОРИЙ.git
git push -u origin main
```

При запросе авторизации введите логин и пароль (или Personal Access Token) GitHub.

---

## Шаг 3. Выбрать способ сборки

Есть два workflow:

| Workflow | Файл | Когда использовать |
|----------|------|--------------------|
| **Build VexGram (Xcode managed)** | `build-unsigned.yml` | Быстрая сборка без настройки сертификатов. Нужен только пуш в GitHub. |
| **CI** (полная сборка) | `build.yml` | Подписанная сборка и создание Release. Нужна папка `fake-codesigning` с сертификатами и профилями. |

Ниже сначала описан простой вариант (шаги 4–6), затем полный (шаги 4a–6a).

---

## Шаг 4. Запустить сборку (простой вариант, без подписи)

1. Откройте ваш репозиторий на GitHub в браузере.
2. Перейдите в раздел **«Actions»** (верхнее меню).
3. В левой колонке выберите workflow **«Build VexGram (Xcode managed)»**.
4. Справа нажмите **«Run workflow»**.
5. В выпадающем списке выберите ветку (обычно **main**).
6. Нажмите зелёную кнопку **«Run workflow»**.

Сборка запустится. Статус отображается в списке запусков (жёлтый — выполняется, зелёный — успех, красный — ошибка).

---

## Шаг 5. Дождаться окончания сборки

1. В **Actions** кликните по текущему (или последнему) запуску workflow.
2. Откройте job **«build»** (одна строка в таблице).
3. Следите за шагами в логе. Сборка может занять **30–60 минут** (первый раз дольше из‑за кэша).
4. Когда все шаги станут зелёными, сборка завершена успешно.

---

## Шаг 6. Скачать VexGram.ipa

1. На странице выполненного run (в **Actions**) в правой части найдите блок **«Artifacts»**.
2. В списке будет артефакт **«VexGram-ipa»**.
3. Нажмите на **«VexGram-ipa»** — на компьютер скачается архив с **VexGram.ipa** внутри.
4. Распакуйте архив и используйте файл **VexGram.ipa**.

Установка на iPhone: через AltStore, Sideloadly или другой способ с вашим Apple ID (IPA из этого workflow подписывается Xcode на стороне GitHub и может требовать повторную подпись под ваш аккаунт).

---

## Вариант с подписанным релизом (workflow «CI»)

Если нужен полноценный подписанный билд и создание Release с прикреплённым IPA.

### Шаг 4a. Подготовить папку fake-codesigning

Текущий workflow **«CI»** (`build.yml`) ожидает папку:

```
build-system/fake-codesigning/
├── certs/          — сертификаты (.p12, .cer)
└── profiles/       — provisioning-профили (.mobileprovision)
```

Эту папку обычно не кладут в публичный репозиторий (секреты). Варианты:

- Создать её локально по инструкции из основного README (раздел про Xcode/IPA и `build-system/fake-codesigning`), затем добавить в репозиторий **приватно** (приватный репо или зашифрованные файлы).
- Либо хранить сертификаты и профили в **GitHub Secrets** и в workflow перед сборкой собирать `fake-codesigning` из секретов (требует доп. настройки workflow).

Пока папки `build-system/fake-codesigning` с валидными `certs` и `profiles` нет, workflow **«CI»** будет падать на шаге с сертификатами/профилями. В этом случае используйте **«Build VexGram (Xcode managed)»** (шаги 4–6 выше).

### Шаг 5a. Запустить workflow «CI»

1. В репозитории откройте **Actions**.
2. Выберите workflow **«CI»**.
3. **Run workflow** → ветка **main** → **Run workflow**.

### Шаг 6a. Скачать IPA из Release

1. После успешного выполнения **«CI»** откройте в репозитории вкладку **«Releases»** (справа от **Code**).
2. Выберите последний релиз (например, «VexGram 11.0 (2501)»).
3. В блоке **Assets** скачайте **VexGram.ipa** и при необходимости **VexGram.DSYMs.zip**.

---

## Частые проблемы

### Workflow не появляется в списке

- Убедитесь, что файлы workflow лежат в репозитории по путям:
  - `.github/workflows/build-unsigned.yml`
  - `.github/workflows/build.yml`
- Сделайте коммит и пуш, подождите несколько секунд и обновите страницу **Actions**.

### Сборка падает с ошибкой Xcode

- В `versions.json` указана версия Xcode (например, 15.2). У GitHub бывают другие предустановленные версии. Можно попробовать в workflow заменить шаг выбора Xcode на использование версии по умолчанию (как в `build-unsigned.yml`: «if Xcode_15.2 exists, use it, else default»).

### Ошибка про сертификаты или provisioning

- Это относится к workflow **«CI»**. Используйте **«Build VexGram (Xcode managed)»** без `fake-codesigning`, либо настройте `build-system/fake-codesigning` как в шаге 4a.

### Артефакт не скачивается

- Артефакты хранятся ограниченное время (по умолчанию 90 дней). Скачайте IPA в течение этого срока или настройте создание Release (workflow **«CI»**), чтобы файл лежал в Release.

---

## Краткая шпаргалка (простой путь)

1. Репозиторий на GitHub создан, код запушен.
2. **Actions** → **Build VexGram (Xcode managed)** → **Run workflow** → **main** → **Run workflow**.
3. Дождаться зелёного статуса.
4. В том же run в **Artifacts** скачать **VexGram-ipa** и взять из архива **VexGram.ipa**.

Готовый IPA можно устанавливать на устройство через AltStore, Sideloadly и т.п. с вашим Apple ID.
